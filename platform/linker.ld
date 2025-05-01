/* Label for the program's entry point */
ENTRY(ResetHandler)

/* Define the end of RAM and limit of stack memory */ 
/* (20 KB SRAM on the STM32F103RB, 20*1024 = 0x5000) */ 
/* (RAM starts at address 0x20000000) */ 
_estack = 0x20005000; 

/* Set minimum size for stack and dynamic memory. */
/* (The linker will generate an error if there is
 * less than this much RAM leftover.) */
/* (1KB) */
_Min_Leftover_RAM = 0x400;

MEMORY 
{ 
FLASH ( rx ) : ORIGIN = 0x08000000 , LENGTH = 128K 
SRAM ( rxw ) : ORIGIN = 0x20000000 , LENGTH = 20K 
} 

SECTIONS
{
    .text :
    {
        KEEP(*(.vector_table))
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _etext = .;
    }> FLASH

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        . = ALIGN(4);
        _edata = .;
    }> SRAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        . = ALIGN(4);
        _ebss = .;
    }> SRAM

    .dynamic_allocations :
    {
        . = ALIGN(4);
        _ssystem_ram = .;
        . = . + _Min_Leftover_RAM;
        . = ALIGN(4);
        _esystem_ram = .;
    } >SRAM

}