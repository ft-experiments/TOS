#include "console_color.h"
#include "console.h"
#include "types.h"
#include "utils.h"


void init(void) {
    //init_vga();
}

void run() {
    init_ascii(WHITE,BLACK);
    clear_ascii_buffer(WHITE, BLACK);
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



