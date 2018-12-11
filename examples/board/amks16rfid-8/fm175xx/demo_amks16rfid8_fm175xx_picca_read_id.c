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
 * \brief fm175xx�������ͺ�ID��ͨ�������ӿ�ʵ��
 *
 * - �������裺
 *   1. ��ȷ���Ӳ����úô��ڡ�
 *   2. ��ȷ���Ӻ����ߡ�
 *   3. ��A�࿨�������߸�Ӧ����
 *
 * - ʵ������
 *   1. ���ڴ�ӡ����Ƭ���ͺźͿ��ż���Ƭ��Ϣ
 *
 * \par Դ����
 * \snippet demo_amks16rfid8_fm175xx_picca_read_id.c src_amks16rfid8_fm175xx_picca_read_id
 *
 * \internal
 * \par Modification history
 * - 1.00 17-11-20  sdq, first implementation.
 * \endinternal
 */

/**
 * \addtogroup demo_kl26_if_dr_fm175xx_picca_read_id
 * \copydoc demo_amks16rfid8_fm175xx_picca_read_id.c
 */

/** [src_amks16rfid8_fm175xx_picca_read_id] */
#include "am_fm175xx.h"
#include "am_fm175xx_reg.h"
#include "am_vdebug.h"
#include "kl26_pin.h"
#include "am_kl26_inst_init.h"
#include "am_fm175xx_ant.h"
#include "am_hwconf_fm175xx.h"
#include "demo_components_entries.h"
#include "demo_amks16rfid8_entries.h"

/**
 * \name ����CD4051������
 * @{
 */
#define __CD4051_PIN_EN PIOB_19
#define __CD4051_PIN_S2 PIOB_18
#define __CD4051_PIN_S1 PIOB_17
#define __CD4051_PIN_S0 PIOB_16

/* ���� fm175xx �����л���Ϣ */
static am_antenna_info_t  __g_antenna_info = {
    {
        __CD4051_PIN_EN,
        __CD4051_PIN_S0,
        __CD4051_PIN_S1,
        __CD4051_PIN_S2
    },
    AM_FM175XX_ANTENNA_EIGHT
};

/**
 * \brief A�࿨�������ͺͿ�������
 */
void demo_amks16rfid8_fm175xx_picca_read_id (void)
{
    am_fm175xx_handle_t handle = am_fm175xx_inst_init();

    am_cd4051_pin_init(&__g_antenna_info);
    /* ѡ������1 */
    am_cd4051_channel_selected(&__g_antenna_info, 0);

    demo_fm175xx_picca_read_id(handle);
}

/** [src_amks16rfid8_fm175xx_picca_read_id] */

/* end of file */