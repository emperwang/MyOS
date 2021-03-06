#ifndef __SYSTEM_H
#define __SYSTEM_H

/*function in main.c*/
extern unsigned char *memcpy(unsigned char *dest,const unsigned char *src,int count);
extern unsigned char *memset(unsigned char *dest,unsigned char val,int count);
extern unsigned short *memsetw(unsigned short *dest,unsigned short val,int count);
extern int strlen(const char* str);
extern unsigned char inportb(unsigned short _port);
extern void outportb(unsigned short _port,unsigned char _data);


/*fucntion in screen.c*/
extern void scroll(void);
extern void move_csr(void);
extern void cls(void);
extern void putch(unsigned char c);
extern void puts(unsigned char* str);
extern void settextcolor(unsigned char forecolor,backcolor);
extern void init_video(void);


#endif
