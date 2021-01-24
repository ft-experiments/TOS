#include "utils.h"
#ifndef CONSOLE_H
#define CONSOLE_H
uint32 ascii_index;
static uint32 next_line_index = 1;
uint8 g_fore_color = WHITE, g_back_color = BLUE;
int digit_ascii_codes[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};



#define ASCII_ADDRESS 0xB8000
#define BUFSIZE 2200

uint16* ascii_buffer;


uint16 ascii_entry(unsigned char ch, uint8 fore_color, uint8 back_color)
{
    uint16 ax = 0;
    uint8 ah = 0, al = 0;

    ah = back_color;
    ah <<= 4;
    ah |= fore_color;
    ax = ah;
    ax <<= 8;
    al = ch;
    ax |= al;

    return ax;
}

void clear_ascii_buffer( uint8 fore_color, uint8 back_color)
{
    uint32 i;
    for(i = 0; i < BUFSIZE; i++){
        (ascii_buffer)[i] = ascii_entry(NULL, fore_color, back_color);
    }
    next_line_index = 1;
    ascii_index = 0;
    next_line_index = 1;
    ascii_index = 0;
}

void init_ascii(uint8 fore_color, uint8 back_color)
{
    ascii_buffer = (uint16*)ASCII_ADDRESS;
    clear_ascii_buffer(fore_color, back_color);
    g_fore_color = fore_color;
    g_back_color = back_color;
}

void print_new_line()
{
    if(next_line_index >= 55){
        next_line_index = 0;
        clear_ascii_buffer(g_fore_color, g_back_color);
    }
    ascii_index = 80*next_line_index;
    next_line_index++;
}

void print_char(char ch)
{
    ascii_buffer[ascii_index] = ascii_entry(ch, g_fore_color, g_back_color);
    ascii_index++;
}

void print_string(char *str)
{
    uint32 index = 0;
    while(str[index]){
        print_char(str[index]);
        index++;
    }
}
void print_text(char *str){
    uint32 index = 0;
    while(str[index]){
        if(str[index]!='\n')
        {
            print_char(str[index]);
        }else{
            print_new_line();
        }
    index++;
    }
}

void print_int(int num)
{
    char str_num[digit_count(num)+1];
    itoa2(num, str_num);
    print_string(str_num);
}

void print_ascii_chars(uint8 fore_color, uint8 back_color)
{
    uint32 i;
    uint16 ax = 0;
    uint8 ah = 0;

    for(i = 1; i < 254;i++){
        ax = 0;
        ah = back_color;
        ah <<= 4;
        ah |= fore_color;
        ax = ah;
        ax <<= 8;
        ax |= i;

        print_int(i);
        print_char(' ');
        print_char(ax);
        print_char(' ');
    }
}
#endif





