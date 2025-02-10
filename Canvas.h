#ifndef PAINTAPP_CANVAS_H
#define PAINTAPP_CANVAS_H

#include <deque>
#include <optional>
#include <iostream>
#include "shapes/Shape.h"
#include "painter/Painter.h"
#include "Color.h"


class Canvas {

private:

    std::deque<std::shared_ptr<shape::Shape>> shapes;
    uint32_t width;
    uint32_t height;

public:

    typedef std::deque<std::shared_ptr<shape::Shape>>::iterator Iterator;
    typedef std::deque<std::shared_ptr<shape::Shape>>::const_iterator const_Iterator;

    Canvas() {};

    Canvas(uint32_t width, uint64_t height): width(width), height(height) {};

    Iterator begin() { return shapes.begin(); };

    Iterator end() { return shapes.end(); };

    void Draw(Painter& painter) const;

    void Add(std::shared_ptr<shape::Shape> shape);

    std::optional<std::shared_ptr<shape::Shape>> getShape(uint32_t x, uint32_t y) const;

    void deleteShape(std::shared_ptr<shape::Shape> shape_to_delete);

    size_t getShapesNumber() const;

    uint32_t getWidth() { return width; }
    
    uint32_t getHeight() { return height; }
};

#endif //PAINTAPP_CANVAS_H
