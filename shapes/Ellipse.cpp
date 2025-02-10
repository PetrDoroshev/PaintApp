#include "Ellipse.h"
#define PI 3.14159265359

namespace shape {
    Ellipse::Ellipse(double x, double y, double width, double height, const Color &outlineColor) : Shape(x, y,
                                                                                                          width,
                                                                                                          height,
                                                                                                          outlineColor) {}
    Ellipse::Ellipse() {}

    void Ellipse::Draw(Painter& painter) const {
           
        painter.DrawEllipse(*this);
    }

    double Ellipse::getArea() const {
        return PI * (width * height) / 4;
    }

    bool Ellipse::Touch(int mx, int my) const {

        int a = width / 2;
        int b = height / 2;

        return (pow((mx - x - a), 2) / (a * a)) + (pow(my - y - b, 2) / (b * b)) < 1;

    }

    std::shared_ptr<Shape> Ellipse::Clone() const {
        return std::shared_ptr<Shape> (new Ellipse(*this));
    }


} // shape