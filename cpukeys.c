#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "cpukeys.h"

static int cpu_key_override_set;
static uint32_t cpu_key_override;

void cpukeys_override_set( uint32_t key ) {
	cpu_key_override = key;
	cpu_key_override_set = 1;
}

void cpukeys_override_clear( void ) {
	cpu_key_override_set = 0;
}

uint32_t cpukeys_get_base( uint32_t cpu_sig ) {
	if (cpu_key_override_set)
		return cpu_key_override;

	switch ( cpu_sig & 0xFFF ) {
#ifdef __cpukeys_h__
		case 0x630: /* Klamath */
		case 0x632: /* Klamath */
			return CPU_KEY_KLAMATH_A;
		case 0x633: /* Klamath */
		case 0x634: /* Klamath */
			return CPU_KEY_KLAMATH_B;
		case 0x650: /* Deschutes */
		case 0x651: /* Deschutes */
			return CPU_KEY_DESCHUTES_A;
		case 0x652: /* Deschutes */
		case 0x653: /* Deschutes */
			return CPU_KEY_DESCHUTES_B;
		case 0x660: /* Dixon */
		case 0x66A: /* Dixon */
		case 0x66D: /* Dixon */
			return CPU_KEY_MOBILE_A;
		case 0x665:
			return CPU_KEY_MOBILE_B;
#endif
		default:
			fprintf( stderr, "Unknown cpu key for CPUID: %03X\n",
			         cpu_sig & 0xFFF );
			exit( EXIT_FAILURE );

	}
}

