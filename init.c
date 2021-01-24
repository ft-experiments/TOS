#include "console_color.h"
#include "console.h"
#include "types.h"
#include "utils.h"
#include "keyboard.h"
uint32 vga_index;
uint16 cursor_pos = 0, cursor_next_line_index = 1;
void init(void) {
    //init_vga();
}
uint8 inb2(uint16 port)
{
    uint8 data;
    asm volatile("inb %1, %0" : "=a"(data) : "Nd"(port));
    return data;
}

void outb2(uint16 port, uint8 data)
{
    asm volatile("outb %0, %1" : : "a"(data), "Nd"(port));
}
void move_cursor(uint16 pos)
{
    outb2(0x3D4, 14);
    outb2(0x3D5, ((pos >> 8) & 0x00FF));
    outb2(0x3D4, 15);
    outb2(0x3D5, pos & 0x00FF);
}
void move_cursor_next_line()
{
    cursor_pos = 80 * cursor_next_line_index;
    cursor_next_line_index++;
    move_cursor(cursor_pos);
}
void gotoxy(uint16 x, uint16 y)
{
    vga_index = 80*y;
    vga_index += x;
    if(y > 0){
        cursor_pos = 80 * cursor_next_line_index * y;
        cursor_next_line_index++;
        move_cursor(cursor_pos);
    }
}
char get_input_keycode()
{
    char ch = 0;
    while((ch = inb(KEYBOARD_PORT)) != 0){
        if(ch > 0)
            return ch;
    }
    return ch;
}

char get_ascii_char(uint8 key_code)
{
    switch(key_code){
        case KEY_A : return 'A';
        case KEY_B : return 'B';
        case KEY_C : return 'C';
        case KEY_D : return 'D';
        case KEY_E : return 'E';
        case KEY_F : return 'F';
        case KEY_G : return 'G';
        case KEY_H : return 'H';
        case KEY_I : return 'I';
        case KEY_J : return 'J';
        case KEY_K : return 'K';
        case KEY_L : return 'L';
        case KEY_M : return 'M';
        case KEY_N : return 'N';
        case KEY_O : return 'O';
        case KEY_P : return 'P';
        case KEY_Q : return 'Q';
        case KEY_R : return 'R';
        case KEY_S : return 'S';
        case KEY_T : return 'T';
        case KEY_U : return 'U';
        case KEY_V : return 'V';
        case KEY_W : return 'W';
        case KEY_X : return 'X';
        case KEY_Y : return 'Y';
        case KEY_Z : return 'Z';
        case KEY_1 : return '1';
        case KEY_2 : return '2';
        case KEY_3 : return '3';
        case KEY_4 : return '4';
        case KEY_5 : return '5';
        case KEY_6 : return '6';
        case KEY_7 : return '7';
        case KEY_8 : return '8';
        case KEY_9 : return '9';
        case KEY_0 : return '0';
        case KEY_MINUS : return '-';
        case KEY_EQUAL : return '=';
        case KEY_SQUARE_OPEN_BRACKET : return '[';
        case KEY_SQUARE_CLOSE_BRACKET : return ']';
        case KEY_SEMICOLON : return ';';
        case KEY_BACKSLASH : return '\\';
        case KEY_COMMA : return ',';
        case KEY_DOT : return '.';
        case KEY_FORESLHASH : return '/';
        case KEY_SPACE : return ' ';
        default : return 0;
    }
}

char getchar()
{
    char keycode = 0;
    keycode = get_input_keycode();
    return get_ascii_char(keycode);
}
void disable_cursor()
{
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
}
void run() {
    init_ascii(WHITE,BLACK);
    clear_ascii_buffer(WHITE, BLACK);
    print_char(getchar());


    print_text("Hallo Welt die\nkuh 123455\nmacht muh");



    // draw_rect(2, 2, 30, 30, YELLOW);
    //  draw_rect(VGA_MAX_WIDTH - 33, 2, 30, 30, YELLOW);
    //  draw_rect(2, VGA_MAX_HEIGHT - 33, 30, 30, YELLOW);
    //  draw_rect(VGA_MAX_WIDTH - 33, VGA_MAX_HEIGHT - 33, 30, 30, YELLOW);
    //  draw_diamond(16, 16, 10, BRIGHT_CYAN);
    //  draw_diamond(VGA_MAX_WIDTH - 18, 16, 10, BRIGHT_CYAN);
    //  draw_diamond(16, VGA_MAX_HEIGHT - 18, 10, BRIGHT_CYAN);
    //  draw_diamond(VGA_MAX_WIDTH - 18, VGA_MAX_HEIGHT - 18, 10, BRIGHT_CYAN);

    //  draw_line(VGA_MAX_WIDTH / 2, 0, VGA_MAX_WIDTH / 2, VGA_MAX_HEIGHT, BRIGHT_GREEN);

    //  for(uint16 i = 0; i < 50; i+=3){
    //     draw_circle(80, 100, 50-i, BRIGHT_RED);
    // }


   // kprintf("Hallo Welt", GREEN);
}



