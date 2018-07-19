
#ifndef HUEVITA_ICONS_HPP
#define HUEVITA_ICONS_HPP


#include <vita2d.h>
#include <string>

#define DEFAULT_FONT_COLOR RGBA8(255, 255, 255, 255)
#define DEFAULT_FONT_SIZE 50

class Icons {
    private:
        vita2d_font *font;
    public:
        Icons();
        void draw(int x, int y, std::string iconCode);
        void draw(int x, int y, std::string iconCode, unsigned int color);
        void draw(int x, int y, std::string iconCode, unsigned int color, unsigned int size);

};


#endif //HUEVITA_ICONS_HPP
