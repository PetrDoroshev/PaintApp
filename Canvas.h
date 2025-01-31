#ifndef PAINTAPP_CANVAS_H
#define PAINTAPP_CANVAS_H

#include <vector>
#include "shapes/Shape.h"
#include "painter/Painter.h"
#include "shapes/manipulator.h"
#include "Color.h"


class Canvas {

private:
    std::vector<std::shared_ptr<shape::Shape>> shapes;
    uint32_t width;
    uint32_t height;

public:

    Canvas(uint32_t width, uint64_t height, Color background_color): width(width), height(height) {};

    void Draw(Painter& painter) const;
    void Add(std::shared_ptr<shape::Shape> shape);
    std::optional<std::shared_ptr<shape::Shape>> getShape(uint32_t x, uint32_t y) const;
    void deleteShape(std::shared_ptr<shape::Shape>);
};

#endif //PAINTAPP_CANVAS_H
