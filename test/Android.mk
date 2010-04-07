#BUILD_LIBVA_TESTS := true

ifeq ($(strip $(BUILD_LIBVA_TESTS)),true)

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := vainfo.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_info

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_01.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_01

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_02.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_02

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_03.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_03

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_04.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_04

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_05.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_05

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_06.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_06

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)



include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_07.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_07

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)



include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_08.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_08

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_09.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_09

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)



include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_10.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_10

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)



include $(CLEAR_VARS)

LOCAL_SRC_FILES := basic/test_11.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_11

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)



include $(CLEAR_VARS)

LOCAL_SRC_FILES := decode/mpeg2vldemo.c
       
LOCAL_CFLAGS += -DHAVE_CONFIG_H        \
       -DIN_LIBVA      \
       -I $(TOPDIR)kernel/include  \
       -I $(TARGET_OUT_HEADERS)/psb_video

LOCAL_C_INCLUDES +=            \
   $(TOPDIR)kernel/include     \
   $(LOCAL_PATH)/../src/       \
   $(LOCAL_PATH)/../src/x11

LOCAL_MODULE := libva_test_12

LOCAL_SHARED_LIBRARIES := libdrm libva

include $(BUILD_EXECUTABLE)

endif
