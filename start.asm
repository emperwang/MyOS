;This is the kernel's entry point.We would either call main here,or we 
;can use this to setup the stack or other nice stuff,like perhaps 
;setting up the GDT and segments.Please note that interrupts are disable
;at this point:More on interrupts later!
;
[BITS 32]
global start
start:
    mov esp,_sys_stack
    jmp stublet



;this is an endless loop here.Make a note of this;later on,we will insert
;an 'extern _main',followed by 'call _main',right before the 'jmp $'
stublet:
    jmp $


;shortly we will add code for loading the gdt right here!


;In just a few pages in this tutorial,we will add our interrupt 
;Service Routines (ISRs) right here!




;Here is the definition of our BSS section.Right now,we'll use it just 
;to store the stack.Remember that a stack actually grows downwards,so
;we declare the size of the data before declaring the identifier 
;'_sys_stack'

SECTION .bss
    resb 8192              ;this reserves 8Kbytes of memory here
_sys_stack:


