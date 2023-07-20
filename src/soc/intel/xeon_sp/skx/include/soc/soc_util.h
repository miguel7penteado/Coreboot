/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _SOC_UTIL_H_
#define _SOC_UTIL_H_

#include <hob_iiouds.h>
#include <hob_memmap.h>

void config_reset_cpl3_csrs(void);

const struct SystemMemoryMapHob *get_system_memory_map(void);

uint8_t get_stack_busno(const uint8_t stack);
uint32_t get_socket_stack_busno(uint32_t socket, uint32_t stack);
uint32_t get_socket_ubox_busno(uint32_t socket);

int soc_get_stack_for_port(int port);
uint8_t get_cxl_node_count(void);

#endif /* _SOC_UTIL_H_ */
