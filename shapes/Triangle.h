//
// Created by doros on 04.10.2023.
//

#ifndef PAINTAPP_TRIANGLE_H
#define PAINTAPP_TRIANGLE_H

#include "Shape.h"

namespace shape {

    class Triangle: public Shape {
    public:
        Triangle(double x, double y, double width, double height, const Color &outlineColor);
        Triangle(const Triangle& triangle) : Shape(triangle) {};
        Triangle();


        void Draw(Painter &painter) const override;

        double getArea() const override;

        bool Touch(int mx, int my) const override;

        Shape *Clone() const override;
    };

} // shape

#endif //PAINTAPP_TRIANGLE_H
