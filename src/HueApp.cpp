
#include "HueApp.hpp"

void HueApp::start() {
    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));

    while (this->run) {
        vita2d_start_drawing();
        vita2d_clear_screen();

        pad->read();
        touch->read();



        vita2d_end_drawing();
        vita2d_swap_buffers();
    }

    vita2d_fini();

    sceKernelExitProcess(0);
}

