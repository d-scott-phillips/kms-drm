/* Copyright 2012-15 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DC_OPP_DCE_H__
#define __DC_OPP_DCE_H__

#include "dc_types.h"
#include "opp.h"
#include "core_types.h"

#define FROM_DCE11_OPP(opp)\
	container_of(opp, struct dce110_opp, base)

enum dce110_opp_reg_type {
	DCE110_OPP_REG_DCP = 0,
	DCE110_OPP_REG_DCFE,
	DCE110_OPP_REG_FMT,

	DCE110_OPP_REG_MAX
};

#define OPP_COMMON_REG_LIST_BASE(id) \
	SRI(REGAMMA_CNTLA_START_CNTL, DCP, id), \
	SRI(REGAMMA_CNTLA_SLOPE_CNTL, DCP, id), \
	SRI(REGAMMA_CNTLA_END_CNTL1, DCP, id), \
	SRI(REGAMMA_CNTLA_END_CNTL2, DCP, id), \
	SRI(REGAMMA_CNTLA_REGION_0_1, DCP, id), \
	SRI(REGAMMA_CNTLA_REGION_2_3, DCP, id), \
	SRI(REGAMMA_CNTLA_REGION_4_5, DCP, id), \
	SRI(REGAMMA_CNTLA_REGION_6_7, DCP, id), \
	SRI(REGAMMA_CNTLA_REGION_8_9, DCP, id), \
	SRI(REGAMMA_CNTLA_REGION_10_11, DCP, id), \
	SRI(REGAMMA_CNTLA_REGION_12_13, DCP, id), \
	SRI(REGAMMA_CNTLA_REGION_14_15, DCP, id), \
	SRI(REGAMMA_LUT_WRITE_EN_MASK, DCP, id), \
	SRI(REGAMMA_LUT_INDEX, DCP, id), \
	SRI(REGAMMA_LUT_DATA, DCP, id), \
	SRI(REGAMMA_CONTROL, DCP, id), \
	SRI(OUTPUT_CSC_C11_C12, DCP, id), \
	SRI(OUTPUT_CSC_C13_C14, DCP, id), \
	SRI(OUTPUT_CSC_C21_C22, DCP, id), \
	SRI(OUTPUT_CSC_C23_C24, DCP, id), \
	SRI(OUTPUT_CSC_C31_C32, DCP, id), \
	SRI(OUTPUT_CSC_C33_C34, DCP, id), \
	SRI(OUTPUT_CSC_CONTROL, DCP, id), \
	SRI(FMT_DYNAMIC_EXP_CNTL, FMT, id), \
	SRI(FMT_BIT_DEPTH_CONTROL, FMT, id), \
	SRI(FMT_CONTROL, FMT, id), \
	SRI(FMT_DITHER_RAND_R_SEED, FMT, id), \
	SRI(FMT_DITHER_RAND_G_SEED, FMT, id), \
	SRI(FMT_DITHER_RAND_B_SEED, FMT, id), \
	SRI(FMT_CLAMP_CNTL, FMT, id), \
	SRI(FMT_CLAMP_COMPONENT_R, FMT, id), \
	SRI(FMT_CLAMP_COMPONENT_G, FMT, id), \
	SRI(FMT_CLAMP_COMPONENT_B, FMT, id)

#define OPP_DCE_80_REG_LIST(id) \
	OPP_COMMON_REG_LIST_BASE(id), \
	SRI(DCFE_MEM_LIGHT_SLEEP_CNTL, CRTC, id), \
	SRI(FMT_TEMPORAL_DITHER_PATTERN_CONTROL, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX, FMT, id)

#define OPP_DCE_100_REG_LIST(id) \
	OPP_COMMON_REG_LIST_BASE(id), \
	SRI(DCFE_MEM_PWR_CTRL, CRTC, id), \
	SRI(DCFE_MEM_PWR_STATUS, CRTC, id), \
	SRI(FMT_TEMPORAL_DITHER_PATTERN_CONTROL, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX, FMT, id)

#define OPP_DCE_110_REG_LIST(id) \
	OPP_COMMON_REG_LIST_BASE(id), \
	SRI(DCFE_MEM_PWR_CTRL, DCFE, id), \
	SRI(DCFE_MEM_PWR_STATUS, DCFE, id), \
	SRI(FMT_TEMPORAL_DITHER_PATTERN_CONTROL, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX, FMT, id)

#define OPP_DCE_112_REG_LIST(id) \
	OPP_COMMON_REG_LIST_BASE(id), \
	SRI(DCFE_MEM_PWR_CTRL, DCFE, id), \
	SRI(DCFE_MEM_PWR_STATUS, DCFE, id), \
	SRI(FMT_TEMPORAL_DITHER_PATTERN_CONTROL, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX, FMT, id), \
	SRI(CONTROL, FMT_MEMORY, id)

#define OPP_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## __ ## field_name ## post_fix

#define OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh)\
	OPP_SF(REGAMMA_CNTLA_START_CNTL, REGAMMA_CNTLA_EXP_REGION_START, mask_sh),\
	OPP_SF(REGAMMA_CNTLA_START_CNTL, REGAMMA_CNTLA_EXP_REGION_START_SEGMENT, mask_sh),\
	OPP_SF(REGAMMA_CNTLA_SLOPE_CNTL, REGAMMA_CNTLA_EXP_REGION_LINEAR_SLOPE, mask_sh),\
	OPP_SF(REGAMMA_CNTLA_END_CNTL1, REGAMMA_CNTLA_EXP_REGION_END, mask_sh),\
	OPP_SF(REGAMMA_CNTLA_END_CNTL2, REGAMMA_CNTLA_EXP_REGION_END_BASE, mask_sh),\
	OPP_SF(REGAMMA_CNTLA_END_CNTL2, REGAMMA_CNTLA_EXP_REGION_END_SLOPE, mask_sh),\
	OPP_SF(REGAMMA_CNTLA_REGION_0_1, REGAMMA_CNTLA_EXP_REGION0_LUT_OFFSET, mask_sh),\
	OPP_SF(REGAMMA_CNTLA_REGION_0_1, REGAMMA_CNTLA_EXP_REGION0_NUM_SEGMENTS, mask_sh),\
	OPP_SF(REGAMMA_CNTLA_REGION_0_1, REGAMMA_CNTLA_EXP_REGION1_LUT_OFFSET, mask_sh),\
	OPP_SF(REGAMMA_CNTLA_REGION_0_1, REGAMMA_CNTLA_EXP_REGION1_NUM_SEGMENTS, mask_sh),\
	OPP_SF(REGAMMA_LUT_WRITE_EN_MASK, REGAMMA_LUT_WRITE_EN_MASK, mask_sh),\
	OPP_SF(REGAMMA_CONTROL, GRPH_REGAMMA_MODE, mask_sh),\
	OPP_SF(OUTPUT_CSC_C11_C12, OUTPUT_CSC_C11, mask_sh),\
	OPP_SF(OUTPUT_CSC_C11_C12, OUTPUT_CSC_C12, mask_sh),\
	OPP_SF(OUTPUT_CSC_CONTROL, OUTPUT_CSC_GRPH_MODE, mask_sh),\
	OPP_SF(FMT_DYNAMIC_EXP_CNTL, FMT_DYNAMIC_EXP_EN, mask_sh),\
	OPP_SF(FMT_DYNAMIC_EXP_CNTL, FMT_DYNAMIC_EXP_MODE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TRUNCATE_EN, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TRUNCATE_DEPTH, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TRUNCATE_MODE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_SPATIAL_DITHER_EN, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_SPATIAL_DITHER_DEPTH, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_SPATIAL_DITHER_MODE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_HIGHPASS_RANDOM_ENABLE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_FRAME_RANDOM_ENABLE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_RGB_RANDOM_ENABLE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_EN, mask_sh),\
	OPP_SF(FMT_DITHER_RAND_R_SEED, FMT_RAND_R_SEED, mask_sh),\
	OPP_SF(FMT_DITHER_RAND_G_SEED, FMT_RAND_G_SEED, mask_sh),\
	OPP_SF(FMT_DITHER_RAND_B_SEED, FMT_RAND_B_SEED, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_EN, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_RESET, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_OFFSET, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_DEPTH, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_LEVEL, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_25FRC_SEL, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_50FRC_SEL, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_75FRC_SEL, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SRC_SELECT, mask_sh),\
	OPP_SF(FMT_CLAMP_CNTL, FMT_CLAMP_DATA_EN, mask_sh),\
	OPP_SF(FMT_CLAMP_CNTL, FMT_CLAMP_COLOR_FORMAT, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_R, FMT_CLAMP_LOWER_R, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_R, FMT_CLAMP_UPPER_R, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_G, FMT_CLAMP_LOWER_G, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_G, FMT_CLAMP_UPPER_G, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_B, FMT_CLAMP_LOWER_B, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_B, FMT_CLAMP_UPPER_B, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_PIXEL_ENCODING, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SUBSAMPLING_MODE, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SUBSAMPLING_ORDER, mask_sh)

#define OPP_COMMON_MASK_SH_LIST_DCE_110(mask_sh)\
	OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh),\
	OPP_SF(DCFE_MEM_PWR_CTRL, DCP_REGAMMA_MEM_PWR_DIS, mask_sh),\
	OPP_SF(DCFE_MEM_PWR_CTRL, DCP_LUT_MEM_PWR_DIS, mask_sh),\
	OPP_SF(DCFE_MEM_PWR_STATUS, DCP_REGAMMA_MEM_PWR_STATE, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, mask_sh)

#define OPP_COMMON_MASK_SH_LIST_DCE_100(mask_sh)\
	OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh),\
	OPP_SF(DCFE_MEM_PWR_CTRL, DCP_REGAMMA_MEM_PWR_DIS, mask_sh),\
	OPP_SF(DCFE_MEM_PWR_CTRL, DCP_LUT_MEM_PWR_DIS, mask_sh),\
	OPP_SF(DCFE_MEM_PWR_STATUS, DCP_REGAMMA_MEM_PWR_STATE, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, mask_sh)

#define OPP_COMMON_MASK_SH_LIST_DCE_112(mask_sh)\
	OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh),\
	OPP_SF(DCFE_MEM_PWR_CTRL, DCP_REGAMMA_MEM_PWR_DIS, mask_sh),\
	OPP_SF(DCFE_MEM_PWR_CTRL, DCP_LUT_MEM_PWR_DIS, mask_sh),\
	OPP_SF(DCFE_MEM_PWR_STATUS, DCP_REGAMMA_MEM_PWR_STATE, mask_sh),\
	OPP_SF(FMT_MEMORY0_CONTROL, FMT420_MEM0_SOURCE_SEL, mask_sh),\
	OPP_SF(FMT_MEMORY0_CONTROL, FMT420_MEM0_PWR_FORCE, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_420_PIXEL_PHASE_LOCKED_CLEAR, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_420_PIXEL_PHASE_LOCKED, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_CBCR_BIT_REDUCTION_BYPASS, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, mask_sh)

#define OPP_COMMON_MASK_SH_LIST_DCE_80(mask_sh)\
	OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh),\
	OPP_SF(DCFE_MEM_LIGHT_SLEEP_CNTL, REGAMMA_LUT_LIGHT_SLEEP_DIS, mask_sh),\
	OPP_SF(DCFE_MEM_LIGHT_SLEEP_CNTL, DCP_LUT_LIGHT_SLEEP_DIS, mask_sh),\
	OPP_SF(DCFE_MEM_LIGHT_SLEEP_CNTL, REGAMMA_LUT_MEM_PWR_STATE, mask_sh)

#define OPP_REG_FIELD_LIST(type) \
	type DCP_REGAMMA_MEM_PWR_DIS; \
	type DCP_LUT_MEM_PWR_DIS; \
	type REGAMMA_LUT_LIGHT_SLEEP_DIS; \
	type DCP_LUT_LIGHT_SLEEP_DIS; \
	type REGAMMA_CNTLA_EXP_REGION_START; \
	type REGAMMA_CNTLA_EXP_REGION_START_SEGMENT; \
	type REGAMMA_CNTLA_EXP_REGION_LINEAR_SLOPE; \
	type REGAMMA_CNTLA_EXP_REGION_END; \
	type REGAMMA_CNTLA_EXP_REGION_END_BASE; \
	type REGAMMA_CNTLA_EXP_REGION_END_SLOPE; \
	type REGAMMA_CNTLA_EXP_REGION0_LUT_OFFSET; \
	type REGAMMA_CNTLA_EXP_REGION0_NUM_SEGMENTS; \
	type REGAMMA_CNTLA_EXP_REGION1_LUT_OFFSET; \
	type REGAMMA_CNTLA_EXP_REGION1_NUM_SEGMENTS; \
	type DCP_REGAMMA_MEM_PWR_STATE; \
	type REGAMMA_LUT_MEM_PWR_STATE; \
	type REGAMMA_LUT_WRITE_EN_MASK; \
	type GRPH_REGAMMA_MODE; \
	type OUTPUT_CSC_C11; \
	type OUTPUT_CSC_C12; \
	type OUTPUT_CSC_GRPH_MODE; \
	type FMT_DYNAMIC_EXP_EN; \
	type FMT_DYNAMIC_EXP_MODE; \
	type FMT_TRUNCATE_EN; \
	type FMT_TRUNCATE_DEPTH; \
	type FMT_TRUNCATE_MODE; \
	type FMT_SPATIAL_DITHER_EN; \
	type FMT_SPATIAL_DITHER_DEPTH; \
	type FMT_SPATIAL_DITHER_MODE; \
	type FMT_TEMPORAL_DITHER_EN; \
	type FMT_TEMPORAL_DITHER_RESET; \
	type FMT_TEMPORAL_DITHER_OFFSET; \
	type FMT_TEMPORAL_DITHER_DEPTH; \
	type FMT_TEMPORAL_LEVEL; \
	type FMT_25FRC_SEL; \
	type FMT_50FRC_SEL; \
	type FMT_75FRC_SEL; \
	type FMT_HIGHPASS_RANDOM_ENABLE; \
	type FMT_FRAME_RANDOM_ENABLE; \
	type FMT_RGB_RANDOM_ENABLE; \
	type FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX; \
	type FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP; \
	type FMT_RAND_R_SEED; \
	type FMT_RAND_G_SEED; \
	type FMT_RAND_B_SEED; \
	type FMT420_MEM0_SOURCE_SEL; \
	type FMT420_MEM0_PWR_FORCE; \
	type FMT_SRC_SELECT; \
	type FMT_420_PIXEL_PHASE_LOCKED_CLEAR; \
	type FMT_420_PIXEL_PHASE_LOCKED; \
	type FMT_CLAMP_DATA_EN; \
	type FMT_CLAMP_COLOR_FORMAT; \
	type FMT_CLAMP_LOWER_R; \
	type FMT_CLAMP_UPPER_R; \
	type FMT_CLAMP_LOWER_G; \
	type FMT_CLAMP_UPPER_G; \
	type FMT_CLAMP_LOWER_B; \
	type FMT_CLAMP_UPPER_B; \
	type FMT_PIXEL_ENCODING; \
	type FMT_SUBSAMPLING_ORDER; \
	type FMT_SUBSAMPLING_MODE; \
	type FMT_CBCR_BIT_REDUCTION_BYPASS;\

struct dce_opp_shift {
	OPP_REG_FIELD_LIST(uint8_t)
};

struct dce_opp_mask {
	OPP_REG_FIELD_LIST(uint32_t)
};

struct dce_opp_registers {
	uint32_t DCFE_MEM_PWR_CTRL;
	uint32_t DCFE_MEM_LIGHT_SLEEP_CNTL;
	uint32_t REGAMMA_CNTLA_START_CNTL;
	uint32_t REGAMMA_CNTLA_SLOPE_CNTL;
	uint32_t REGAMMA_CNTLA_END_CNTL1;
	uint32_t REGAMMA_CNTLA_END_CNTL2;
	uint32_t REGAMMA_CNTLA_REGION_0_1;
	uint32_t REGAMMA_CNTLA_REGION_2_3;
	uint32_t REGAMMA_CNTLA_REGION_4_5;
	uint32_t REGAMMA_CNTLA_REGION_6_7;
	uint32_t REGAMMA_CNTLA_REGION_8_9;
	uint32_t REGAMMA_CNTLA_REGION_10_11;
	uint32_t REGAMMA_CNTLA_REGION_12_13;
	uint32_t REGAMMA_CNTLA_REGION_14_15;
	uint32_t REGAMMA_LUT_WRITE_EN_MASK;
	uint32_t REGAMMA_LUT_INDEX;
	uint32_t DCFE_MEM_PWR_STATUS;
	uint32_t REGAMMA_LUT_DATA;
	uint32_t REGAMMA_CONTROL;
	uint32_t OUTPUT_CSC_C11_C12;
	uint32_t OUTPUT_CSC_C13_C14;
	uint32_t OUTPUT_CSC_C21_C22;
	uint32_t OUTPUT_CSC_C23_C24;
	uint32_t OUTPUT_CSC_C31_C32;
	uint32_t OUTPUT_CSC_C33_C34;
	uint32_t OUTPUT_CSC_CONTROL;
	uint32_t FMT_DYNAMIC_EXP_CNTL;
	uint32_t FMT_BIT_DEPTH_CONTROL;
	uint32_t FMT_CONTROL;
	uint32_t FMT_DITHER_RAND_R_SEED;
	uint32_t FMT_DITHER_RAND_G_SEED;
	uint32_t FMT_DITHER_RAND_B_SEED;
	uint32_t FMT_TEMPORAL_DITHER_PATTERN_CONTROL;
	uint32_t FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX;
	uint32_t FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX;
	uint32_t CONTROL;
	uint32_t FMT_CLAMP_CNTL;
	uint32_t FMT_CLAMP_COMPONENT_R;
	uint32_t FMT_CLAMP_COMPONENT_G;
	uint32_t FMT_CLAMP_COMPONENT_B;
};

struct dce110_regamma {
	struct gamma_curve arr_curve_points[16];
	struct curve_points arr_points[3];
	uint32_t hw_points_num;
	struct hw_x_point *coordinates_x;
	struct pwl_result_data *rgb_resulted;

	/* re-gamma curve */
	struct pwl_float_data_ex *rgb_regamma;
	/* coeff used to map user evenly distributed points
	 * to our hardware points (predefined) for gamma 256 */
	struct pixel_gamma_point *coeff128;
	struct pixel_gamma_point *coeff128_oem;
	/* coeff used to map user evenly distributed points
	 * to our hardware points (predefined) for gamma 1025 */
	struct pixel_gamma_point *coeff128_dx;
	/* evenly distributed points, gamma 256 software points 0-255 */
	struct gamma_pixel *axis_x_256;
	/* evenly distributed points, gamma 1025 software points 0-1025 */
	struct gamma_pixel *axis_x_1025;
	/* OEM supplied gamma for regamma LUT */
	struct pwl_float_data *rgb_oem;
	/* user supplied gamma */
	struct pwl_float_data *rgb_user;
	uint32_t extra_points;
	bool use_half_points;
	struct fixed31_32 x_max1;
	struct fixed31_32 x_max2;
	struct fixed31_32 x_min;
	struct fixed31_32 divider1;
	struct fixed31_32 divider2;
	struct fixed31_32 divider3;
};

/* OPP RELATED */
#define TO_DCE110_OPP(opp)\
	container_of(opp, struct dce110_opp, base)

struct dce110_opp {
	struct output_pixel_processor base;
	const struct dce_opp_registers *regs;
	const struct dce_opp_shift *opp_shift;
	const struct dce_opp_mask *opp_mask;
	struct dce110_regamma regamma;
};

bool dce110_opp_construct(struct dce110_opp *opp110,
	struct dc_context *ctx,
	uint32_t inst,
	const struct dce_opp_registers *regs,
	const struct dce_opp_shift *opp_shift,
	const struct dce_opp_mask *opp_mask);

void dce110_opp_destroy(struct output_pixel_processor **opp);

/* REGAMMA RELATED */
void dce110_opp_power_on_regamma_lut(
	struct output_pixel_processor *opp,
	bool power_on);

bool dce110_opp_program_regamma_pwl(
	struct output_pixel_processor *opp,
	const struct pwl_params *params);

void dce110_opp_set_regamma_mode(struct output_pixel_processor *opp,
		enum opp_regamma mode);

void dce110_opp_set_csc_adjustment(
	struct output_pixel_processor *opp,
	const struct out_csc_color_matrix *tbl_entry);

void dce110_opp_set_csc_default(
	struct output_pixel_processor *opp,
	const struct default_adjustment *default_adjust);

/* FORMATTER RELATED */
void dce110_opp_program_bit_depth_reduction(
	struct output_pixel_processor *opp,
	const struct bit_depth_reduction_params *params);

void dce110_opp_program_clamping_and_pixel_encoding(
	struct output_pixel_processor *opp,
	const struct clamping_and_pixel_encoding_params *params);

void dce110_opp_set_dyn_expansion(
	struct output_pixel_processor *opp,
	enum dc_color_space color_sp,
	enum dc_color_depth color_dpth,
	enum signal_type signal);

void dce110_opp_program_fmt(
	struct output_pixel_processor *opp,
	struct bit_depth_reduction_params *fmt_bit_depth,
	struct clamping_and_pixel_encoding_params *clamping);

void dce110_opp_set_clamping(
	struct dce110_opp *opp110,
	const struct clamping_and_pixel_encoding_params *params);

#endif
