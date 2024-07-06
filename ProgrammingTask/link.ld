
/*
Author: Ahmed Raza
Description: This linker script sets the memory layout for a RISC-V
executable.
It places the .text section at address 0x80000000 with a page
alignment of 0x1000.
*/

SECTIONS
{
    . = 0x80000000;           /* Code section starts at 0x80000000 */
    .text : { *(.text) }

    . = 0x80001000;           /* Data section starts at 0x80001000 */
    .data : { *(.data) }
    .bss : { *(.bss) }
}
