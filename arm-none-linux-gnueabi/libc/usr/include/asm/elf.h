#ifndef __ASMARM_ELF_H
#define __ASMARM_ELF_H


/*
 * ELF register definitions..
 */

#include <asm/ptrace.h>
#include <asm/user.h>

typedef unsigned long elf_greg_t;
typedef unsigned long elf_freg_t[3];

#define EM_ARM	40
#define EF_ARM_APCS26 0x08
#define EF_ARM_SOFT_FLOAT 0x200
#define EF_ARM_EABI_MASK 0xFF000000

#define R_ARM_NONE	0
#define R_ARM_PC24	1
#define R_ARM_ABS32	2
#define R_ARM_CALL	28
#define R_ARM_JUMP24	29

#define ELF_NGREG (sizeof (struct pt_regs) / sizeof(elf_greg_t))
typedef elf_greg_t elf_gregset_t[ELF_NGREG];

typedef struct user_fp elf_fpregset_t;

/*
 * These are used to set parameters in the core dumps.
 */
#define ELF_CLASS	ELFCLASS32
#ifdef __ARMEB__
#define ELF_DATA	ELFDATA2MSB
#else
#define ELF_DATA	ELFDATA2LSB
#endif
#define ELF_ARCH	EM_ARM


#endif
