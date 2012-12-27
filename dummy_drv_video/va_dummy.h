/*
 * Copyright (c) 2007-2009 Intel Corporation. All Rights Reserved.
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
 * IN NO EVENT SHALL INTEL AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * \file va_dummy.h
 * \brief The Core API
 *
 * This file contains the \ref api_core "Core API".
 */

#ifndef _VA_DUMMY_H_
#define _VA_DUMMY_H_

#include <va/va_version.h>
#include <va/va_backend.h>

#ifdef __cplusplus
extern "C" {
#endif

//typedef void* VADisplay;        /* window system dependent */

static VAStatus va_openDriver_dummy(VADisplay dpy, char *driver_name);

/*
 * Initialize the library
 */
VAStatus vaInitialize_dummy (
    VADisplay dpy,
    int *major_version,	 /* out */
    int *minor_version 	 /* out */
);

#ifdef __cplusplus
}
#endif

#endif
