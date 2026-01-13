#ifndef PAINTAPP_COLOR_H
#define PAINTAPP_COLOR_H

#include <cstdint>

class Color {

public:

    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;

    Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) { red = r; green = g; blue = b; alpha = a; };

};


#endif