#include "utils.h"

void kprintf(char input[],int textcolor) {




    int i;
    char *video = (char *) 0xb8000;

// C-Strings haben ein Nullbyte als Abschluss
    for (i = 0; input[i] != '\0'; i++) {

// Zeichen i in den Videospeicher kopieren
        video[i * 2] = input[i];

// 0x07 = Hellgrau auf Schwarz
        video[i * 2 + 1] = textcolor;
    }
}



void kprintfint(int in,int color) {

    char *temp = (char *) 0x00;

  //  char *temp2 =
 kprintf(itoa(in, temp,10),color);

}

void kprintfhex(char hex,int color) {  //TODO geht noch net

    char *temp = (char *) 0x00;

    //  char *temp2 =
    kprintf(itoa(hex, temp,16),color);

}


void clear_console() {
    char *video = (char *) 0xb8000;

    for(int i = 0;i<10000;i++) { //TODO hier die Size einstellen

        video[i] = 0x00;

    }


}







