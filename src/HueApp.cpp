
#include "HueApp.hpp"
#include "ui/Icons.hpp"

void HueApp::start() {

    pad = new Pad();
    touch = new Touch();

    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));

    Icons *icons = new Icons();

    while (this->run) {
        vita2d_start_drawing();
        vita2d_clear_screen();

        pad->read();
        touch->read();

        icons->draw(100, 100, "\uF59F");

        vita2d_end_drawing();
        vita2d_swap_buffers();
    }

    vita2d_fini();

    sceKernelExitProcess(0);
}

