#include "Shape.h"

namespace shape {

    Shape::Shape(double x, double y, double width, double height, const Color& outline_color) : x(x), y(y), 
                                                                                                width(width),
                                                                                                height(height),
                                                                                                outline_color(outline_color) {}

    Shape::Shape(double x, double y, double width, double height, const Color &outline_color, const Color &fill_color) : 
                                                                                          x(x), y(y), 
                                                                                          width(width),
                                                                                          height(height),
                                                                                          outline_color(outline_color),
                                                                                          fill_color(fill_color){}
    

    Shape::Shape(uint32_t x, uint32_t y) : x(x), y(y), width(MIN_WIDTH), height(MIN_HEIGHT) {}

    Shape::Shape(uint32_t x, uint32_t y, double width, double height): x(x), y(y), width(width), height(height) 
    {
    }

    Shape::Shape() : x(MIN_X), y(MIN_Y), width(MIN_WIDTH), height(MIN_HEIGHT) {};

    double Shape::getX() const {
        return x;
    }

    double Shape::getY() const {
        return y;
    }

    double Shape::getWidth() const {
        return width;
    }

    double Shape::getHeight() const {
        return height;
    }

    const Color &Shape::getOutlineColor() const {
        return outline_color;
    }

    void Shape::setOutlineColor(const Color &outlineColor) {
        outline_color = outlineColor;
    }

    void Shape::setFillColor(const Color& fillColor) {
        fill_color = fillColor;
    }

    Color Shape::getFillColor() const {
        return fill_color;
    }

    bool Shape::Touch(int mx, int my) const {
        
        return (mx > x && 
                mx < x + width && 
                my > y && 
                my < y + height);
    }

    Shape::Shape(const Shape& shape) {

        this->x = shape.x;
        this->y = shape.y;
        this->width = shape.width;
        this->height = shape.height;
        this->outline_color = shape.outline_color;
    }

    std::shared_ptr<Shape> Shape::Clone() const {
        return nullptr;
    }

    void Shape::setWidth(double width) {
        Shape::width = std::abs(width);
    }

    void Shape::setHeight(double height) {
        Shape::height = std::abs(height);
    }

    void Shape::setPos(double new_x, double new_y) {
        x = new_x;
        y = new_y;
    }

    void Shape::setSize(double new_width, double new_height) {

        setWidth(new_width);
        setHeight(new_height);
    }

    double Shape::getArea() const {
        return width * height;
    }

}

