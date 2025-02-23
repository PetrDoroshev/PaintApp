#ifndef PAINTAPP_ELLIPSE_H
#define PAINTAPP_ELLIPSE_H

#include "Shape.h"

namespace shape {

    class Ellipse: public Shape {

    public:

        Ellipse(double x, double y, double width, double height, const Color& outlineColor);
        Ellipse();
        Ellipse(const Ellipse &ellipse) : Shape(ellipse) {};
        void Draw(Painter &painter) override;
        double getArea() const override;
        bool Touch(int mx, int my) const override;
        std::shared_ptr<Shape> Clone() const override;

    };

} // shape

#endif //PAINTAPP_ELLIPSE_H
