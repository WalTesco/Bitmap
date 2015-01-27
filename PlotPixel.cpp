#include <iostream.h>

void plotpixel ( char color , int xpos,  int ypos); //Function prototype for pixel plotter
void setscreen (char mode); //Function prototype for setting screen mode

int main()
{
	setscreen(0x13);    //Set screen to mode 13h 320X200 256 colors indexed
	plotpixel(3 , 100 , 100);
	return 0;
}
void plotpixel(char color ,int xpos ,int ypos)
{
	asm{mov ah , 0x0c}; //Write pixel
	asm{mov al , color}; //Store pixel color to register
	asm{mov bh , 0x01}; //Video memory page number , first visible page
	asm{mov cx , xpos}; //Store X position to register

	asm{mov dx , ypos}; //Store Y position to register

	asm{int 0x10}; //Call video service interrupt
	return;
}
void setscreen(char mode)
{
	asm{mov ah , 0x00}; //Set screen mode first byte to 00
	asm{mov al , mode}; //Set most significant byte to user input typically x13
	asm{int 0x10}; //Call video service BIOS interrupt
	return;
}
