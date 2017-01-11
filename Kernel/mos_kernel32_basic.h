/*
File: mos_kernel32_basic.h
Author: leosncz
Purpose:
This file contains datas and functions the kernel might uses.
*/
#define RAMSCREEN 0xB8000 // Video address.
#define MOS_KERNEL_VERSION "ALPHA" // Must contains five characters. For example if version is 1.0 : #define MOS_KERNEL_VERSION "1.000"
void kernelOutputWhiteCharacter(char colX, char rowY, char characterToPrint) // It prints a white character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(RAMSCREEN+2*(rowY*80+colX))+1;
	*video=0xF; // White on black attribute.
}

void kernelOutputRedCharacter(char colX, char rowY, char characterToPrint) // It prints a red character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(RAMSCREEN+2*(rowY*80+colX))+1;
	*video=0xC; // Red on black attribute.
}

void kernelOutputGreenCharacter(char colX, char rowY, char characterToPrint) // It prints a green character at I(colX;rowY).
{
	unsigned char *video = (unsigned char*)RAMSCREEN+2*(rowY*80+colX);
	*video=characterToPrint;
	video=(unsigned char*)(RAMSCREEN+2*(rowY*80+colX))+1;
	*video=0xA; // Green on black attribute.
}

void kernelOutputGreenString(char colX, char rowY, char string[],int size) // It prints a green string.
{
	char colX_ = colX;
	char rowY_ = rowY;
	for(int i=0;i<size;i++)
	{
		kernelOutputGreenCharacter(colX_,rowY_,string[i]);
		colX_++;
	}
}

void kernelOutputWhiteString(char colX, char rowY, char string[],int size) // It prints a white string.
{
	char colX_ = colX;
	char rowY_ = rowY;
	for(int i=0;i<size;i++)
	{
		kernelOutputWhiteCharacter(colX_,rowY_,string[i]);
		colX_++;
	}
}

void kernelOutputRedString(char colX, char rowY, char string[],int size) // It prints a red string.
{
	char colX_ = colX;
	char rowY_ = rowY;
	for(int i=0;i<size;i++)
	{
		kernelOutputRedCharacter(colX_,rowY_,string[i]);
		colX_++;
	}
}

void clearScreen() // It clears the screen.
{
	unsigned char *video = (unsigned char*)RAMSCREEN;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		video[i]=' '; // Nothing (space).
		i++;
		video[i]=0xF; // White on black attribute.
		i++;
	}
}

void kernelOutputBasicInfos(char startRowY) // Print informations about the kernel.
{
	char string1[31] = "Kernel>MOS's kernel version is ";
	char mosKernelVersion[5] = MOS_KERNEL_VERSION;
	kernelOutputGreenString(0,startRowY,string1,31);
	kernelOutputRedString(31,startRowY,mosKernelVersion,5);
}
