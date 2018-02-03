/*
 * created by Le MIn 2017/12/09
 */

#ifndef _MVISOR_CONFIG_H_
#define _MVISOR_CONFIG_H_

#define CONFIG_RAM_START_ADDRESS	0x80000000
#define CONFIG_RAM_SIZE			0x40000000

#define CONFIG_MVISOR_START_ADDRESS	CONFIG_RAM_START_ADDRESS
#define CONFIG_MVISOR_RAM_SIZE		(128 * 1024 *1024)

#define CONFIG_MVISOR_STACK_BASE	(CONFIG_RAM_START_ADDRESS + CONFIG_MVISOR_RAM_SIZE)

#define CONFIG_MAX_CPU_NR		(8)
#define CONFIG_NUM_OF_CPUS		(4)
#define CONFIG_VM_MAX_VCPU		(CONFIG_NUM_OF_CPUS)
#define CONFIG_MAX_VM			(4)

#define CONFIG_LOG_LEVEL		4

#define CONFIG_ARM_AARCH64		1
#define CONFIG_ARCH_ARMV8_A		1

#define CONFIG_MAX_PHYSICAL_SIZE	(0x100000000)

#define CONFIG_GRANULE_SIZE_64K

#ifdef CONFIG_GRANULE_SIZE_64K
	#define MMU_TTB_LEVEL1_ALIGN	(0x10000)
	#define MMU_TTB_LEVEL2_ALIGN	(0x10000)
	#define MMU_TTB_LEVEL1_SIZE	(0x10000)
	#define MMU_TTB_LEVEL2_SIZE	((CONFIG_MAX_PHYSICAL_SIZE >> 29) << 16)
#elif CONFIG_GRANULE_SIZE_16K
	#define MMU_TTB_LEVEL1_ALIGN	(0x4000)
	#define MMU_TTB_LEVEL2_ALIGN	(0x4000)
	#define MMU_TTB_LEVEL1_SIZE	(0x4000)
	#define MMU_TTB_LEVEL2_SIZE	((CONFIG_MAX_PHYSICAL_SIZE >> 25) << 14)
#else	/* 4k granule size  */
	#define MMU_TTB_LEVEL1_ALIGN	(0x1000)
	#define MMU_TTB_LEVEL2_ALIGN	(0x1000)
	#define MMU_TTB_LEVEL1_SIZE	(0x1000)
	#define MMU_TTB_LEVEL2_SIZE	((CONFIG_MAX_PHYSICAL_SIZE >> 30) << 12)
#endif

#endif