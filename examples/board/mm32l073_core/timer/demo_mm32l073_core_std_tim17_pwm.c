/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief TIM17 定时器 PWM 例程，通过标准接口实现
 *
 * - 实验现象：
 *   1. PIOA_7(TIM17_CH1) PIOB_7(TIM17_CH1N)输出互补 2KHz 的 PWM，占空比为 50%；
 *
 * \par 源代码
 * \snippet demo_mm32l073_core_std_tim17_pwm.c src_mm32l073_core_std_tim17_pwm
 *
 * \internal
 * \par Modification history
 * - 1.00 17-04-22  nwt, first implementation
 * \endinternal
 */ 

/**
 * \addtogroup demo_if_mm32l073_core_std_tim17_pwm
 * \copydoc demo_mm32l073_core_std_tim17_pwm.c
 */

/** [src_mm32l073_core_std_tim17_pwm] */
#include "ametal.h"
#include "am_vdebug.h"
#include "am_mm32_tim_pwm.h"
#include "am_mm32l073_inst_init.h"
#include "demo_std_entries.h"
#include "demo_mm32l073_core_entries.h"

/**
 * \brief 例程入口
 */
void demo_mm32l073_core_std_tim17_pwm_entry (void)
{
    AM_DBG_INFO("demo mm32l073_core std tim17 pwm!\r\n");

    demo_std_timer_pwm_entry(am_mm32l073_tim17_pwm_inst_init(), AM_MM32_TIM_PWM_CH1);
}
/** [src_mm32l073_core_std_tim17_pwm] */

/* end of file */
