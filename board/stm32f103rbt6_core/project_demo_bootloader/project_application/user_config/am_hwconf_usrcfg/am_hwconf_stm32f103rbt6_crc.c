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
 * \brief STM32F103RBT6 CRC �û������ļ�
 * \sa am_hwconf_stm32f103rbt6_crc.c
 *
 * \internal
 * \par Modification history
 * - 1.00 17-08-30  fra, first implementation
 * \endinternal
 */

#include "am_stm32f103rbt6.h"
#include "ametal.h"
#include "am_clk.h"
#include "am_stm32f103rbt6_crc.h"

/**
 * \addtogroup am_if_src_hwconf_stm32f103rbt6_crc
 * \copydoc am_hwconf_stm32f103rbt6_crc.c
 * @{
 */

/** \brief CRCƽ̨��ʼ�� */
void __stm32f103rbt6_crc_plfm_init (void)
{

    /* ʹ��CRCʱ�� */
    am_clk_enable(CLK_CRC);
}

/** \brief ���CRCƽ̨��ʼ�� */
void __stm32f103rbt6_crc_plfm_deinit (void)
{
    am_clk_disable(CLK_CRC);
}

/** \brief CRC �豸��Ϣ */
static const am_stm32f103rbt6_crc_devinfo_t __g_crc_devinfo = {
     STM32F103RBT6_CRC_BASE,               /**< \brief CRC�Ĵ������ַ */
    __stm32f103rbt6_crc_plfm_init,         /**< \brief ƽ̨��ʼ�� */
    __stm32f103rbt6_crc_plfm_deinit        /**< \brief ƽ̨ȥ��ʼ�� */
};

/** \brief CRC�豸���� */
static am_stm32f103rbt6_crc_dev_t __g_crc_dev;

/** \brief CRC ʵ����ʼ�������CRC��׼������ */
am_crc_handle_t am_stm32f103rbt6_crc_inst_init (void)
{
    return am_stm32f103rbt6_crc_init(&__g_crc_dev, &__g_crc_devinfo);
}

/** \brief CRC ʵ�����ʼ�� */
void am_stm32f103rbt6_crc_inst_deinit (am_crc_handle_t handle)
{
    am_stm32f103rbt6_crc_deinit(handle);
}

/**
 * @}
 */

/* end of file */