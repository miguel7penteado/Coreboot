/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	0x10ec0888, /* Codec Vendor / Device ID: Realtek ALC888 */
	0x80862008, /* Subsystem ID */
	15,	    /* Number of 4 dword sets */
	AZALIA_SUBVENDOR(2, 0x80862008),
	AZALIA_PIN_CFG(2, 0x11, 0x411111f0),
	AZALIA_PIN_CFG(2, 0x12, 0x411111f0),
	AZALIA_PIN_CFG(2, 0x14, 0x01014410),
	AZALIA_PIN_CFG(2, 0x15, 0x411111f0),
	AZALIA_PIN_CFG(2, 0x16, 0x411111f0),
	AZALIA_PIN_CFG(2, 0x17, 0x99130140),
	AZALIA_PIN_CFG(2, 0x18, 0x01a19c50),
	AZALIA_PIN_CFG(2, 0x19, 0x02a19960),
	AZALIA_PIN_CFG(2, 0x1a, 0x0181345f),
	AZALIA_PIN_CFG(2, 0x1b, 0x02214120),
	AZALIA_PIN_CFG(2, 0x1c, 0x411111f0),
	AZALIA_PIN_CFG(2, 0x1d, 0x4004c601),
	AZALIA_PIN_CFG(2, 0x1e, 0x99430130),
	AZALIA_PIN_CFG(2, 0x1f, 0x411111f0),

	0x80862805, /* Codec Vendor / Device ID: Intel */
	0x80862008, /* Subsystem ID */
	4,	    /* Number of 4 dword sets */
	AZALIA_SUBVENDOR(3, 0x80862008),
	AZALIA_PIN_CFG(3, 0x05, 0x58560010),
	AZALIA_PIN_CFG(3, 0x06, 0x18560020),
	AZALIA_PIN_CFG(3, 0x07, 0x58560030),
};

const u32 pc_beep_verbs[0] = {};

AZALIA_ARRAY_SIZES;
