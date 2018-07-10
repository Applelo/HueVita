#ifndef HUEVITA_HUEAPP_HH
#define HUEVITA_HUEAPP_HH

#include <psp2/kernel/processmgr.h>

#include <string>

#include <vita2d.h>

#include "utils/Pad.hpp"
#include "utils/Touch.hpp"

class HueApp {
private:
   int run = 1;
   Pad *pad = new Pad();
   Touch *touch = new Touch();
public:
    void start();

};


#endif //HUEVITA_HUEAPP_HH
