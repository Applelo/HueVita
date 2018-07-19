

#include "Icons.hpp"

Icons::Icons() {
    font = vita2d_load_font_file("app0:assets/fonts/materialdesignicons.ttf");
}

void Icons::draw(int x, int y, std::string iconCode) {
    vita2d_font_draw_text(font, x, y, DEFAULT_FONT_COLOR, DEFAULT_FONT_SIZE, iconCode.c_str());
}

void Icons::draw(int x, int y, std::string iconCode, unsigned int color) {
    vita2d_font_draw_text(font, x, y, color, DEFAULT_FONT_SIZE, iconCode.c_str());
}

void Icons::draw(int x, int y, std::string iconCode, unsigned int color, unsigned int size) {
    vita2d_font_draw_text(font, x, y, color, size, iconCode.c_str());
}