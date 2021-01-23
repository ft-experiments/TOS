#include "console_color.h"
#include "console.h"
#include "vga.h"


void init(void) {
    init_vga();
}

void run() {
    draw_rect(0, 0, VGA_MAX_WIDTH - 1, VGA_MAX_HEIGHT - 1, BRIGHT_GREEN);
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
    while(1) {
        int x = 240;
        while (x>10) {
            clear_console();
            for (uint16 i = 0; i < 20; i += 1) {
                draw_circle(x, x, i, BRIGHT_MAGENTA);
            }


            if (x > 10)
                x--;

        }
        x = 0;
        while (x<240) {
            clear_console();
            for (uint16 i = 0; i < 20; i += 1) {
                draw_circle(x, 240-x, i, BRIGHT_BLUE);
            }


            if (x < 240)
                x++;

        }
    int counter =0;
        while(counter<99999999) {
            counter++;
        }

        clear_screen();
    }



    kprintf("Hallo Welt", GREEN);
}



