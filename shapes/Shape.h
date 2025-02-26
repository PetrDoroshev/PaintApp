#ifndef PAINTAPP_SHAPE_H
#define PAINTAPP_SHAPE_H

#include <cstdint>
#include <optional>
#include "../Color.h"
#include "../painter/Painter.h"

namespace shape {

    const double MIN_X = 0.0;
    const double MIN_Y = 0.0;
    const double MIN_WIDTH = 1.0;
    const double MIN_HEIGHT = 1.0;

    class Shape {

    public:
        Shape(double x, double y, double width, double height, const Color& outline_color);

        Shape(double x, double y, double width, double height, const Color& outline_color, const Color& fill_color);

        Shape(const Shape& shape);

        Shape(uint32_t x, uint32_t y);

        Shape(uint32_t x, uint32_t y, double width, double height);

        Shape();

        virtual ~Shape() = default;

        double getX() const;

        double getY() const;

        virtual void setPos(double new_x, double new_y);

        double getWidth() const;

        double getHeight() const;

        virtual void setSize(double new_width, double new_height);

        const Color& getOutlineColor() const;

        void setFillColor(const Color& fillColor);

        Color getFillColor() const;

        void setOutlineColor(const Color& outlineColor);

        virtual bool Touch(int mx, int my) const;

        virtual void Draw(Painter& painter) = 0;

        virtual std::shared_ptr<Shape> Clone() const;

        virtual double getArea() const;

        void setWidth(double width);

        void setHeight(double height);

    protected:

        double x;
        double y;
        double width;
        double height;
        Color outline_color = Color(0, 0, 0, 255);
        Color fill_color = Color(0, 0, 0, 0);
    };
};

#endif //PAINTAPP_SHAPE_H
