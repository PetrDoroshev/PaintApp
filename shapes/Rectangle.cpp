#include "Rectangle.h"

namespace shape {
    
    Rectangle::Rectangle() {}
    Rectangle::Rectangle(double x, double y, double width, double height,
                         const Color &outlineColor) : Shape(x, y, width, height, outlineColor) {}

    Rectangle::Rectangle(double x, double y, double width, double height) : Shape(x, y, width, height) {}


    Rectangle::Rectangle(double x, double y, double width, double height,
                         const Color &outlineColor, const Color& fill_color) : Shape(x, y, width, height, outlineColor, fill_color) {}

  
    void Rectangle::Draw(Painter& painter) const {

        painter.DrawRect(*this);
    }

    double Rectangle::getArea() const {

        return width * height;
    }

    Shape *Rectangle::Clone() const {
        return new Rectangle(*this);
    }

}


