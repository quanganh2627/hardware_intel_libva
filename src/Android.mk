LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES :=         \
   va.c                \
   x11/va_x11.c            \
   x11/va_dricommon.c      \
   x11/dri2_util.c

LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/x11       \
   $(TOPDIR)kernel/include/drm

LOCAL_COPY_HEADERS_TO := libva/va

LOCAL_COPY_HEADERS :=          \
   va.h                \
   va_backend.h            \
   va_version.h            \
   x11/va_dri.h            \
   x11/va_dri2.h           \
   x11/va_x11.h            \
   x11/va_dricommon.h

LOCAL_MODULE := libva

LOCAL_SHARED_LIBRARIES := libdl libdrm libcutils

include $(BUILD_SHARED_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))
