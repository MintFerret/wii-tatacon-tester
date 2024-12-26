#include <grrlib.h>

#include <stdlib.h>
#include <stdio.h>
#include <wiiuse/wpad.h>

//data
#include "TnT_ttf.h"
#include "taiko_png.h"
#include "donnkat_png.h"
#include "notes_png.h"
int main(int argc, char **argv) {
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();
        // Load the font from memory
    //load fonts and textures
    int DON = 0;
    int KAT = 0;
    char DON_disp[16];
    char KAT_disp[16];
    GRRLIB_texImg *TaikoDrum = GRRLIB_LoadTexture(taiko_png);
    GRRLIB_texImg *TaikoDonKat = GRRLIB_LoadTexture(donnkat_png);
    GRRLIB_texImg *TaikoNotes = GRRLIB_LoadTexture(notes_png);
    GRRLIB_ttfFont *TaikoFont = GRRLIB_LoadTTF(TnT_ttf, TnT_ttf_size);
    GRRLIB_InitTileSet(TaikoDonKat, 226, 492, 0);
    GRRLIB_InitTileSet(TaikoNotes, 100, 100, 0);
   GRRLIB_SetBackgroundColour (255, 205, 51, 1);
    sprintf(DON_disp, "%d", DON);
            sprintf(KAT_disp, "%d", KAT);
    // Initialise the Wiimotes
    WPAD_Init();

    // Loop forever
    while(1) {

        WPAD_ScanPads();  // Scan the Wiimotes

        // If [HOME] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;


        
        // ---------------------------------------------------------------------
        // Place your drawing code here
        // ---------------------------------------------------------------------
        // images
        GRRLIB_DrawImg(130, 130, TaikoDrum, 0, 0.75, 0.75, 0xFFFFFFFF);
        GRRLIB_DrawTile(410,120,TaikoNotes,0,0.5,0.5,0xFFFFFFFF,0);
        GRRLIB_DrawTile(410,50,TaikoNotes,0,0.5,0.5,0xFFFFFFFF,1);
        // text
            GRRLIB_PrintfTTF(130,40,TaikoFont,"I'm on a wii! Da-don!" ,24,0x000000FF); // white 0xFFFFFFFF // black 0x000000FF //
        GRRLIB_PrintfTTF(490,130,TaikoFont, DON_disp ,20,0x000000FF);
        GRRLIB_PrintfTTF(490,60,TaikoFont, KAT_disp ,20,0x000000FF);
        // input
                    if(WPAD_ButtonsHeld(0) & WPAD_CLASSIC_BUTTON_A) {
			        //Right Don
                        GRRLIB_DrawTile(300,130,TaikoDonKat,0,0.75,0.75,0xFFFFFFFF,1);
			}

			if(WPAD_ButtonsHeld(0) & WPAD_CLASSIC_BUTTON_B ) {
                //Left Don
				GRRLIB_DrawTile(130,130,TaikoDonKat,0,0.75,0.75,0xFFFFFFFF,0);
			}
			
			if(WPAD_ButtonsHeld(0) & WPAD_CLASSIC_BUTTON_X) {
		        //Right Kat
                GRRLIB_DrawTile(300,130,TaikoDonKat,0,0.75,0.75,0xFFFFFFFF,3);
			}
			
			if(WPAD_ButtonsHeld(0) & WPAD_CLASSIC_BUTTON_Y) {
			    //Left Kat
                GRRLIB_DrawTile(130,130,TaikoDonKat,0,0.75,0.75,0xFFFFFFFF,2);
			}
        /// Counter
                    if(WPAD_ButtonsDown(0) & WPAD_CLASSIC_BUTTON_A){
                            DON++;
                            sprintf(DON_disp, "%d", DON);
			}
                            if(WPAD_ButtonsDown(0) & WPAD_CLASSIC_BUTTON_B){
                            DON++;
                            sprintf(DON_disp, "%d", DON);
			}
                    if(WPAD_ButtonsDown(0) & WPAD_CLASSIC_BUTTON_X){
                            KAT++;
                            sprintf(KAT_disp, "%d", KAT);
			}
                            if(WPAD_ButtonsDown(0) & WPAD_CLASSIC_BUTTON_Y){
                            KAT++;
                            sprintf(KAT_disp, "%d", KAT);
			}
        
                     if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A) {
			DON = 0;
            KAT = 0;
            sprintf(DON_disp, "%d", DON);
            sprintf(KAT_disp, "%d", KAT);
		}
        GRRLIB_Render();  // Render the frame buffer to the TV
    }
    GRRLIB_FreeTexture(TaikoNotes);
    GRRLIB_FreeTexture(TaikoDrum);
    GRRLIB_FreeTexture(TaikoDonKat);
    GRRLIB_FreeTTF(TaikoFont);
    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}