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
    extern _main
    call _main
    jmp $


;shortly we will add code for loading the gdt right here!
global _gdt_flush
extern _gp
_gdt_flush:
    lgdt [_gp];  ;load  the GDT with our '_gp' whcih is a special pointer
    mov ax,0x10  ;0x10 is the offset in the GDT to our data segment 
    mov ds,ax
    mov es,ax
    mov fs,ax
    mov gs,ax
    mov ss,ax
    jmp 0x08:flush2  ;0x08 is the offset to our code segment;Far jump!
flush2:
    ret             ;returns back to the c code!

;In just a few pages in this tutorial,we will add our interrupt 
;Service Routines (ISRs) right here!




;Here is the definition of our BSS section.Right now,we'll use it just 
;to store the stack.Remember that a stack actually grows downwards,so
;we declare the size of the data before declaring the identifier 
;'_sys_stack'

SECTION .bss
    resb 8192              ;this reserves 8Kbytes of memory here
_sys_stack:


