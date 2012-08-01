/*
 *  Copyright 2011-12 ARM Limited
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
 * NE10 Library : math/NE10_divc.neon.c
 */

#include "NE10_types.h"
#include "macros.h"

#include <assert.h>
#include <arm_neon.h>

#include <stdio.h>
#include <stdlib.h>

ne10_result_t divc_float_neon (ne10_float32_t * dst, ne10_float32_t * src, const ne10_float32_t cst, ne10_uint32_t count)
{
    ne10_uint32_t ii = 0;
    ne10_float32_t d[4];
    NE10_XC_OPERATION_FLOAT_NEON
    (
        /* a single division operation */
        float32x4_t rec = vrecpeq_f32 (n_cst);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst, rec), rec);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst, rec), rec);
        n_dst = vmulq_f32 (n_src , rec);
        ,
        /* a single division operation */
        float32x2_t rec = vrecpe_f32 (n_tmp_cst);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst, rec), rec);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst, rec), rec);
        n_tmp_src = vmul_f32 (n_tmp_src, rec);
    );
}

ne10_result_t divc_vec2f_neon (ne10_vec2f_t * dst, ne10_vec2f_t * src, const ne10_vec2f_t * cst, ne10_uint32_t count)
{
    NE10_XC_OPERATION_VEC2F_NEON
    (
        /* a single division operation */
        float32x4_t rec = vrecpeq_f32 (n_cst);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst, rec), rec);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst, rec), rec);
        n_dst = vmulq_f32 (n_src , rec);
        ,
        /* a single division operation */
        float32x2_t rec = vrecpe_f32 (n_tmp_cst);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst, rec), rec);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst, rec), rec);
        n_tmp_src = vmul_f32 (n_tmp_src, rec);
    );
}

ne10_result_t divc_vec3f_neon (ne10_vec3f_t * dst, ne10_vec3f_t * src, const ne10_vec3f_t * cst, ne10_uint32_t count)
{
    NE10_XC_OPERATION_VEC3F_NEON
    (
        /* three division operations */
        float32x4_t rec = vrecpeq_f32 (n_cst1);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst1, rec), rec);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst1, rec), rec);
        n_dst1 = vmulq_f32 (n_src1 , rec);

        rec = vrecpeq_f32 (n_cst2);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst2, rec), rec);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst2, rec), rec);
        n_dst2 = vmulq_f32 (n_src2 , rec);

        rec = vrecpeq_f32 (n_cst3);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst3, rec), rec);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst3, rec), rec);
        n_dst3 = vmulq_f32 (n_src3 , rec);
        ,
        /* three division operations */
        float32x2_t rec = vrecpe_f32 (n_tmp_cst.val[0]);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst.val[0], rec), rec);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst.val[0], rec), rec);
        n_tmp_src.val[0] = vmul_f32 (n_tmp_src.val[0] , rec);

        rec = vrecpe_f32 (n_tmp_cst.val[1]);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst.val[1], rec), rec);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst.val[1], rec), rec);
        n_tmp_src.val[1] = vmul_f32 (n_tmp_src.val[1] , rec);

        rec = vrecpe_f32 (n_tmp_cst.val[2]);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst.val[2], rec), rec);
        rec = vmul_f32 (vrecps_f32 (n_tmp_cst.val[2], rec), rec);
        n_tmp_src.val[2] = vmul_f32 (n_tmp_src.val[2] , rec);
    );
}

ne10_result_t divc_vec4f_neon (ne10_vec4f_t * dst, ne10_vec4f_t * src, const ne10_vec4f_t * cst, ne10_uint32_t count)
{
    NE10_XC_OPERATION_VEC4F_NEON
    (
        /* a single division operation */
        float32x4_t rec = vrecpeq_f32 (n_cst);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst, rec), rec);
        rec = vmulq_f32 (vrecpsq_f32 (n_cst, rec), rec);
        n_dst = vmulq_f32 (n_src , rec);
    );
}
