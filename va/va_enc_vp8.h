/*
 * Copyright (c) 2007-2012 Intel Corporation. All Rights Reserved.
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
 * \file va_enc_vp8.h
 * \brief VP8 encoding API
 *
 * This file contains the \ref api_enc_vp8 "VP8 encoding API".
 */

#ifndef VA_ENC_VP8_H
#define VA_ENC_VP8_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup api_enc_vp8 VP8 encoding API
 *
 * @{
 */

/**
 * \brief VP8 Encoding Sequence Parameter Buffer Structure
 *
 * This structure conveys sequence level parameters.
 *
 */
typedef struct  _VAEncSequenceParameterBufferVP8
{
    /* profile */
    unsigned int profile;
    /* frame width in pixels */
    unsigned int frame_width;
    /* frame height in pixels */
    unsigned int frame_height;
    /* frame rate */
    unsigned int frame_rate;
    /* whether to enable error resilience features */
    unsigned int error_resilient;
    /* number of token partitions */
    unsigned int num_token_partitions;
    /* auto keyframe placement, non-zero means enable auto keyframe placement */
    unsigned int kf_auto;
    /* keyframe minimum interval */
    unsigned int kf_min_dist;
    /* keyframe maximum interval */
    unsigned int kf_max_dist;

    /* quality setting, equivalent to VP8E_SET_CPUUSED */
    unsigned int quality_setting;

    /* RC related fields. RC modes are set with VAConfigAttribRateControl */
    /* For VP8, CBR implies HRD conformance and VBR implies no HRD conformance */

    /* target bit-rate */
    unsigned int bits_per_second;
    /* min QP */
    unsigned int min_qp;
    /* max QP */
    unsigned int max_qp;
    /* RC undershoot percentage */
    unsigned int rc_undershoot;
    /* RC overshoot percentage */
    unsigned int rc_overshoot;
    /* HRD buffer size */
    unsigned int hrd_buf_size;
    /* HRD buffer initial fullness */
    unsigned int hrd_buf_initial_fullness;
    /* HRD buffer optimal fullness */
    unsigned int hrd_buf_optimal_fullness;

} VAEncSequenceParameterBufferVP8;

/**
 * \brief VP8 Encoding Picture Parameter Buffer Structure
 *
 * This structure conveys picture level parameters.
 *
 */
typedef struct  _VAEncPictureParameterBufferVP8
{
    /* specifies the "last" reference frame */
    VASurfaceID last_ref_frame;
    /* specifies the "golden" reference frame */
    VASurfaceID golden_ref_frame;
    /* specifies the "alternate" referrence frame */
    VASurfaceID alt_ref_frame;
    /* surface to store reconstructed frame  */
    VASurfaceID reconstructed_frame;
    /* buffer to store coded data */
    VABufferID coded_buf;

    union {
        struct {
	    /* force this frame to be a keyframe */
            unsigned int force_kf		: 1;
	    /* don't reference the last frame */
            unsigned int no_ref_last		: 1;
	    /* don't reference the golden frame */
            unsigned int no_ref_gf		: 1;
	    /* don't reference the alternate reference frame */
            unsigned int no_ref_arf		: 1;
        } bits;
        unsigned int value;
    } pic_flags;

} VAEncPictureParameterBufferVP8;

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* VA_ENC_VP8_H */
