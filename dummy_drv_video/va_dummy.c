/*
 * Copyright (c) 2007 Intel Corporation. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <va/va.h>
#include <va/va_backend.h>
#include <va/va_trace.h>
#include <va/va_fool.h>
#include <va/va_version.h>
#include <va_dummy.h>
#include <dummy_drv_video.h>

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

#ifdef ANDROID
#include <cutils/log.h>
#include <hardware/gralloc.h>
#include <system/graphics.h>
#include <hardware/hardware.h>
#endif

#define CTX(dpy) (((VADisplayContextP)dpy)->pDriverContext)
#define CHECK_DISPLAY(dpy) if( !vaDisplayIsValid(dpy) ) { return VA_STATUS_ERROR_INVALID_DISPLAY; }

#define ASSERT		assert

#ifdef ANDROID
static hw_module_t const *module;
gralloc_module_t *mAllocMod; /* get by force hw_module_t */
#endif

static VAStatus va_openDriver_dummy(VADisplay dpy, char *driver_name);

VAStatus vaInitialize_dummy (
    VADisplay dpy,
    int *major_version,	 /* out */
    int *minor_version 	 /* out */
)
{
    const char *driver_name_env = NULL;
    char *driver_name = NULL;
    VAStatus vaStatus;
	int err;

    CHECK_DISPLAY(dpy);

    va_TraceInit(dpy);

    va_FoolInit(dpy);

    va_infoMessage("VA-API version %s\n", VA_VERSION_S);

    driver_name_env = getenv("LIBVA_DRIVER_NAME");

    vaStatus = VA_STATUS_SUCCESS;
    driver_name = "libdummy";

    if (VA_STATUS_SUCCESS == vaStatus) {

        vaStatus = va_openDriver_dummy(dpy, driver_name);

        va_infoMessage("va_openDriver() returns %d\n", vaStatus);

        *major_version = VA_MAJOR_VERSION;
        *minor_version = VA_MINOR_VERSION;
    }

#ifdef ANDROID
    err = hw_get_module(GRALLOC_HARDWARE_MODULE_ID, &module);
    if (err) {
        LOGE("FATAL: can't find the %s module", GRALLOC_HARDWARE_MODULE_ID);
        return -1;
    } else
        LOGD("hw_get_module returned\n");
    mAllocMod = (gralloc_module_t *)module;
#endif
    return vaStatus;
}

#define DRIVER_EXTENSION	"_drv_video.so"
static VAStatus va_openDriver_dummy(VADisplay dpy, char *driver_name)
{
    VADriverContextP ctx = CTX(dpy);
    VAStatus vaStatus = VA_STATUS_ERROR_UNKNOWN;
    char *search_path = NULL;
    char *saveptr;
    char *driver_dir;

    if (geteuid() == getuid())
        /* don't allow setuid apps to use LIBVA_DRIVERS_PATH */
        search_path = getenv("LIBVA_DRIVERS_PATH");
    if (!search_path)
        search_path = VA_DRIVERS_PATH;

    search_path = strdup((const char *)search_path);
    driver_dir = strtok_r(search_path, ":", &saveptr);

    while (driver_dir) {
        void *handle = NULL;
        char *driver_path = (char *) malloc( strlen(driver_dir) +
                                             strlen(driver_name) +
                                             strlen(DRIVER_EXTENSION) + 2 );
        strncpy( driver_path, driver_dir, strlen(driver_dir) + 1);
        strncat( driver_path, "/", strlen("/") );
        strncat( driver_path, driver_name, strlen(driver_name) );
        strncat( driver_path, DRIVER_EXTENSION, strlen(DRIVER_EXTENSION) );

        va_infoMessage("Trying to open %s\n", driver_path);

#ifndef ANDROID
        handle = dlopen( driver_path, RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE );
#else
        handle = dlopen( driver_path, RTLD_NOW| RTLD_GLOBAL);
#endif
        if (!handle) {
            /* Don't give errors for non-existing files */
            if (0 == access( driver_path, F_OK))
                va_errorMessage("dlopen of %s failed: %s\n", driver_path, dlerror());
        } else {
			VADriverInit init_func = NULL;
			char init_func_s[256];
			int i;

			static const struct {
				int major;
				int minor;
			} compatible_versions[] = {
				{ VA_MAJOR_VERSION, VA_MINOR_VERSION },
				{ 0, 33 },
				{ 0, 32 },
				{ -1, }
			};

			for (i = 0; compatible_versions[i].major >= 0; i++) {
				vaStatus = VA_STATUS_SUCCESS;
				init_func = (VADriverInit)dlsym(handle, "VA_DRIVER_INIT_FUNC");
				if (init_func) {
					va_infoMessage("Found init function %s\n", "VA_DRIVER_INIT_FUNC");
					break;
				}
			}

			vaStatus = VA_DRIVER_INIT_FUNC(ctx);
            if (VA_STATUS_SUCCESS != vaStatus) {
                va_errorMessage("%s init failed\n", driver_path);
                dlclose(handle);
            }

            if (VA_STATUS_SUCCESS == vaStatus)
                ctx->handle = handle;

            free(driver_path);
            break;
        }
        free(driver_path);
        driver_dir = strtok_r(NULL, ":", &saveptr);

    }
	free(search_path);

	return vaStatus;
}
