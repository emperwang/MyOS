#include <system.h>


unsigned char *memcpy(unsigned char *dest,const unsigned char *src,int count)
{
   const char *sp = (const char*)src;
   char * dp = (char *) dest;
   for(;count!=0;count--)
       *dp++ = *sp++;
   return dest;
}

unsigned char *memset(unsigned char *dest,unsigned char cal,int count)
{
    char *temp = (char *)dest;
    for(;count != 0;count--)
        *temp++ = val;
    return dest;
}

unsigned short *memsetw(unsigned short *dest,unsigned short val,int count
)
{
    unsigned short *temp = (unsigned short*)dest;
    for(;count!=0;count--)
        *temp++=val;
    return dest;
}


int strlen(const char *str)
{
     int retval;
     for(retval=0;*str != '\0';str++)
         retval++;
     return retval;
}

/*We will usr this to write to I/O ports to send bytes to devices.This 
will be used in the next tutorial for changing the textmode cursor
position.Again,we use some inline assemble for the stuff that simply
cannot be done in c*/
unsigned char inportb(unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__("inb %1,%0"
                        :"=a"(rv)
                        :"dN"(_port));
    return rv;
}

/*We will use this to write to I/O ports to send bytes to devices.This
 *will be used in the next tutorial for changing the textmode cursor
 *position.Again we use some inline assembly for the stuff that simply
 *cannot be done in C
 * */
void outportb(unsigned short _port,unsigned char _data)
{
    __asm__ __volatile__("outb %1,%0"
                        :
                        :"dN"(_port),"a"(_data));
}

/*This is a very simply main() function.All it does is sit in an infinite
 *loop.This will be like our 'idle' loop.
 */

void main()
{
    
    for(;;);
}



