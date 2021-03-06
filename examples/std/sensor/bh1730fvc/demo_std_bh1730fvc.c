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
 * \brief 光传感器 BH1730FVC 例程，通过标准接口实现
 *
 * - 实验现象：
 *   1. 每过一秒，通过串口打印光强值
 *
 * \par 源代码
 * \snippet demo_std_bh1730fvc.c src_std_bh1730fvc
 *
 * \internal
 * \par Modification history
 * - 1.00 19-02-20  yrz, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_std_bh1730fvc
 * \copydoc demo_std_bh1730fvc.c
 */

#include "ametal.h"
#include "am_vdebug.h"
#include "am_sensor.h"
#include "am_sensor_bh1730fvc.h"
#include "am_delay.h"

/**
 * \brief 例程入口
 */
void demo_std_bh1730fvc_entry (am_sensor_handle_t handle)
{
    /* BH1730FVC提供的所有通道ID列举 */
    const int id[2] = {AM_BH1730FVC_CHAN_1};

    /* 储存通道数据的缓存 */
    am_sensor_val_t data[1];

    /*
     * 列出光照数据的名字和单位字符串，便于打印
     */
    const char *data_name_string[] = {"Light"};
    const char *data_unit_string[] = {"Lux"};

    am_sensor_enable(handle, id, 1, data);

    while(1) {
        am_sensor_data_get(handle, id, 1, data);

        if (AM_SENSOR_VAL_IS_VALID(data[0])) { /* 该通道数据有效，可以正常使用 */
                am_kprintf("The %s is : %d %s.\r\n", data_name_string[0],
                                                     data[0].val,
                                                     data_unit_string[0]);   
        } else {       //该通道数据无效，数据获取失败
            am_kprintf("The %s get failed!\r\n", data_name_string[0]);
        }
        am_mdelay(1000);
    }
}

/* end of file */
