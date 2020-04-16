

void kprintf(char input[]) {




    int i;
    char *video = (char *) 0xb8000;

// C-Strings haben ein Nullbyte als Abschluss
    for (i = 0; input[i] != '\0'; i++) {

// Zeichen i in den Videospeicher kopieren
        video[i * 2] = input[i];

// 0x07 = Hellgrau auf Schwarz
        video[i * 2 + 1] = 0x07;
    }
}


