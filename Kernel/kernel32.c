/*
File: kernel32.c
Author: leosncz
Purpose:
This is the kernel's main entry point.
*/
#include "mos_kernel32_basic.c"
void kmain() // Kernel's main entry point.
{
	/* 
	We are in VGA Mode (NOT IN TEXT MODE !).
	The VGA mode has been set up by our bootloader.
	*/
	
	#if(DEV_STATUS == DEBUG_MODE) // We are in DEBUG mode(default).
	#endif
	
	#if(DEV_STATUS == RELEASE_MODE) // We are in RELEASE mode.
	#endif
	
	while(1) // Infinite loop (so it does not execute garbage).
	{
		writeHorizontalLineVGA(0, 0, 100, VGA_COLOR_RED);
		/*
		If everything is fine, you should be able to see a little red line on the top of your screen.
		*/
	}; 
}
