/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef _SPR_DDR_H_
#define _SPR_DDR_H_

#include <types.h>

/* SPD Byte 11: Module Nominal Voltage
 * currently DDR4 only supports 1.2V, DDR5 only supports 1.1V. */
#define SPD_VDD_DDR4 3
#define SPD_VDD_DDR5 0
#define SPD_TYPE_DDR5 0x12

/* DDR_*_TCK_MIN are in picoseconds */
#define DDR_1000_TCK_MIN 2000
#define DDR_1066_TCK_MIN 1875
#define DDR_1200_TCK_MIN 1667
#define DDR_1333_TCK_MIN 1500
#define DDR_1400_TCK_MIN 1429
#define DDR_1600_TCK_MIN 1250
#define DDR_1800_TCK_MIN 1110
#define DDR_1866_TCK_MIN 1071
#define DDR_2000_TCK_MIN 1000
#define DDR_2133_TCK_MIN 938
#define DDR_2200_TCK_MIN 909
#define DDR_2400_TCK_MIN 833
#define DDR_2600_TCK_MIN 769
#define DDR_2666_TCK_MIN 750
#define DDR_2800_TCK_MIN 714
#define DDR_2933_TCK_MIN 682
#define DDR_3000_TCK_MIN 667
#define DDR_3200_TCK_MIN 625
#define DDR_3400_TCK_MIN 589
#define DDR_3466_TCK_MIN 577
#define DDR_3600_TCK_MIN 556
#define DDR_3733_TCK_MIN 536
#define DDR_3800_TCK_MIN 527
#define DDR_4000_TCK_MIN 500
#define DDR_4200_TCK_MIN 477
#define DDR_4266_TCK_MIN 469
#define DDR_4400_TCK_MIN 455
#define DDR_4800_TCK_MIN 417
#define DDR_5200_TCK_MIN 385
#define DDR_5600_TCK_MIN 358
#define DDR_6000_TCK_MIN 334
#define DDR_6400_TCK_MIN 313
#define DDR_6800_TCK_MIN 295
#define DDR_7200_TCK_MIN 278
#define DDR_7600_TCK_MIN 264
#define DDR_8000_TCK_MIN 250
#define DDR_8400_TCK_MIN 239

unsigned int get_max_memory_speed(unsigned int commonTck);
unsigned int get_ddr_millivolt(unsigned int ddr_voltage);
bool mainboard_dimm_slot_exists(uint8_t socket, uint8_t channel, uint8_t slot);

#endif /* _SPR_DDR_H_ */
