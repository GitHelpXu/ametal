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
 * \brief aml17x bootloader�����õ�Ӧ�ù���
 *
 * \internal
 * \par Modification history
 * - 1.00 20-8-20  xjy, first implementation
 * \endinternal
 */

/**
 * \brief �������
 */
#include "ametal.h"
#include "am_board.h"
#include "am_vdebug.h"
#include "am_delay.h"
#include "demo_aml17x_core_entries.h"

int am_main (void)
{
    AM_DBG_INFO("Start up successful!\r\n");

    /* ����bootloader �Ĳ���Ӧ�ó��� demo */
    demo_hc32l17x_core_single_application_entry();

    /* uart ˫��bootloader �Ĳ���Ӧ�ó��� demo */
//    demo_hc32l17x_core_double_application_entry();

    while (1) {

    }
}

/* end of file */