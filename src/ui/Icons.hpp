
#ifndef HUEVITA_ICONS_HPP
#define HUEVITA_ICONS_HPP


#include <vita2d.h>
#include <string>
#include <map>

#define DEFAULT_FONT_COLOR RGBA8(255, 255, 255, 255)
#define DEFAULT_FONT_SIZE 50

class Icons {
    private:
        vita2d_font *font;
        std::map<const char*,  const char*> iconsReferences;
    public:
        Icons();
        void draw(int x, int y, const char* iconCode);
        void draw(int x, int y, const char* iconCode, unsigned int color);
        void draw(int x, int y, const char* iconCode, unsigned int color, unsigned int size);

};


#endif //HUEVITA_ICONS_HPP
