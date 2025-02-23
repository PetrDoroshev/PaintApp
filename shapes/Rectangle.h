#ifndef PAINTAPP_RECTANGLE_H
#define PAINTAPP_RECTANGLE_H

#include "Shape.h"

namespace shape {

    class Rectangle : public Shape {

    public:
    
        Rectangle();
        Rectangle(double x, double y, double width, double height);
        Rectangle(double x, double y, double width, double height, const Color& outline_color);
        Rectangle(double x, double y, double width, double height, const Color& outline_color, const Color& fill_color);
        
        explicit Rectangle(const Rectangle &rectangle) : Shape(rectangle) {};

        void Draw(Painter &painter) override; 

        double getArea() const override;

        std::shared_ptr<Shape> Clone() const override;

    };
}

#endif //PAINTAPP_RECTANGLE_H
