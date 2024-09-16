#include "Ellipse.h"
#define PI 3.14159265359

namespace shape {
    Ellipse::Ellipse(double x, double y, double width, double height, const Color &outlineColor) : Shape(x, y,
                                                                                                          width,
                                                                                                          height,
                                                                                                          outlineColor) {}
    Ellipse::Ellipse() {}

    void Ellipse::Draw(Painter& painter) const {
           
        /*
        QPen pen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin);
        painter.setPen(pen);
        painter.drawEllipse(QRectF(x, y, width, height));
        */

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

    Shape *Ellipse::Clone() const {
        return new Ellipse(*this);
    }


} // shape