 /*
  * Machine type & revision
  */
 #if defined(CONFIG_MACH_FIORE)
 #define MACHINE_TYPE        1
 #define MACHINE_REVSION     (CONFIG_FIORE_REV & 0x7F)
 #elif defined(CONFIG_MACH_GRANDPRIX)
 #define MACHINE_TYPE        3
 #define MACHINE_REVSION     (CONFIG_GRANDPRIX_REV & 0x7F)
 #elif defined(CONFIG_MACH_EGIS)
 #define MACHINE_TYPE        4
 #define MACHINE_REVSION     (CONFIG_EGIS_REV & 0x7F)
 #elif defined(CONFIG_MACH_RIEDEL)
 #define MACHINE_TYPE        0
 #define MACHINE_REVSION     CONFIG_RIEDEL_REV
 #elif defined(CONFIG_MACH_NEVERLAND)
 #define MACHINE_TYPE        7
 #define MACHINE_REVSION     (CONFIG_NEVERLAND_REV & 0x7F)
 #elif defined(CONFIG_MACH_GA6410)
 #define MACHINE_TYPE        8
 #define MACHINE_REVSION     (CONFIG_GA6410_REV & 0x7F)
 #elif defined(CONFIG_MACH_CAPELA)
 #define MACHINE_TYPE        9
 #define MACHINE_REVSION     (CONFIG_CAPELA_REV & 0x7F)
 #elif defined(CONFIG_MACH_UNIV)
 #define MACHINE_TYPE		 10
 #define MACHINE_REVSION	 (CONFIG_UNIV_REV & 0x7F)
 #endif



#ifdef SEC_CSC
#define MSM_PARTITION_NUM			8
#else
#define MSM_PARTITION_NUM			7
#endif
#define BLOCK_SIZE					(128 * 1024)

#define A9BOOT_PART_ID				0
#define AMSS_PART_ID				1
#define A11BOOT_PART_ID				2
#define KERNEL_PART_ID				3
#define SYSTEM_PART_ID				4
#define USERDATA_PART_ID			5
#define RECOVERY_PART_ID			6 
#define CACHE_PART_ID			    7 
#define PARAMETER_PART_ID			8

#define A9BOOT_FLASH_BASE			(0x00000000)
#define A9BOOT_BLOCK_NUM			18
#define A9BOOT_FLASH_LEN			BLOCK_SIZE * A9BOOT_BLOCK_NUM
#define A9BOOT_START_BLOCK			0

#define AMSS_FLASH_BASE				(A9BOOT_FLASH_BASE + A9BOOT_FLASH_LEN)
#define AMSS_BLOCK_NUM				165
#define AMSS_FLASH_LEN				BLOCK_SIZE * AMSS_BLOCK_NUM
#define AMSS_START_BLOCK			AMSS_FLASH_BASE / BLOCK_SIZE

#define A11BOOT_FLASH_BASE			(AMSS_FLASH_BASE + AMSS_FLASH_LEN)
#define A11BOOT_BLOCK_NUM			8
#define A11BOOT_FLASH_LEN			BLOCK_SIZE * A11BOOT_BLOCK_NUM
#define A11BOOT_START_BLOCK			A11BOOT_FLASH_BASE / BLOCK_SIZE

#define RFBACKUP_FLASH_BASE			(A11BOOT_FLASH_BASE + A11BOOT_FLASH_LEN)
#define RFBACKUP_BLOCK_NUM			45
#define RFBACKUP_FLASH_LEN			BLOCK_SIZE * RFBACKUP_BLOCK_NUM
#define RFBACKUP_START_BLOCK		RFBACKUP_FLASH_BASE / BLOCK_SIZE

#define EFS2_FLASH_BASE				(RFBACKUP_FLASH_BASE + RFBACKUP_FLASH_LEN)
#define EFS2_BLOCK_NUM				63
#define EFS2_FLASH_LEN				BLOCK_SIZE * EFS2_BLOCK_NUM
#define EFS2_START_BLOCK			EFS2_FLASH_BASE / BLOCK_SIZE

#define KERNEL_FLASH_BASE			(EFS2_FLASH_BASE + EFS2_FLASH_LEN)
#define KERNEL_BLOCK_NUM			25	
#define KERNEL_FLASH_LEN			BLOCK_SIZE * KERNEL_BLOCK_NUM
#define KERNEL_START_BLOCK			KERNEL_FLASH_BASE / BLOCK_SIZE


/* ORION PARTITION */
#define SYSTEM_FLASH_BASE           (KERNEL_FLASH_BASE + KERNEL_FLASH_LEN)
#define SYSTEM_BLOCK_NUM            700
#define SYSTEM_FLASH_LEN            BLOCK_SIZE * SYSTEM_BLOCK_NUM
#define SYSTEM_START_BLOCK          SYSTEM_FLASH_BASE / BLOCK_SIZE

#define USERDATA_FLASH_BASE         (SYSTEM_FLASH_BASE + SYSTEM_FLASH_LEN)
#define USERDATA_BLOCK_NUM          10
#define USERDATA_FLASH_LEN          BLOCK_SIZE * USERDATA_BLOCK_NUM
#define USERDATA_START_BLOCK        USERDATA_FLASH_BASE / BLOCK_SIZE

#define RECOVERY_FLASH_BASE         (USERDATA_FLASH_BASE + USERDATA_FLASH_LEN)
#define RECOVERY_BLOCK_NUM          25
#define RECOVERY_FLASH_LEN          BLOCK_SIZE * RECOVERY_BLOCK_NUM
#define RECOVERY_START_BLOCK        RECOVERY_FLASH_BASE / BLOCK_SIZE

#define CACHE_FLASH_BASE            (RECOVERY_FLASH_BASE + RECOVERY_FLASH_LEN)
#define CACHE_BLOCK_NUM             700
#define CACHE_FLASH_LEN             BLOCK_SIZE * CACHE_BLOCK_NUM
#define CACHE_START_BLOCK           CACHE_FLASH_BASE / BLOCK_SIZE

#define DATA_FLASH_BASE             (CACHE_FLASH_BASE + CACHE_FLASH_LEN)
#define DATA_BLOCK_NUM              286
#define DATA_FLASH_LEN              BLOCK_SIZE * DATA_BLOCK_NUM
#define DATA_START_BLOCK            DATA_FLASH_BASE / BLOCK_SIZE

#define PARAMETER_FLASH_BASE        (DATA_FLASH_BASE + DATA_FLASH_LEN)
#define PARAMETER_BLOCK_NUM         2
#define PARAMETER_FLASH_LEN         BLOCK_SIZE * PARAMETER_BLOCK_NUM
#define PARAMETER_START_BLOCK       PARAMETER_FLASH_BASE / BLOCK_SIZE


struct orion_param {
	unsigned current_usb_pid;
	char 	usb_serial_number[16];
};

extern void msm_read_param(struct orion_param *orion_param_data);
extern void msm_write_param(struct orion_param *orion_param_data);