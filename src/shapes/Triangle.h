//
// Created by doros on 04.10.2023.
//

#ifndef PAINTAPP_TRIANGLE_H
#define PAINTAPP_TRIANGLE_H

#include "Shape.h"
#include "../PointF.h"

namespace shape {

    class Triangle : public Shape {
    private:

        std::array<PointF, 3> points;
        
        void computePoints();

    public:
        Triangle(double x, double y, double width, double height, const Color& outlineColor);
        Triangle(const Triangle& triangle);
        Triangle();

        void Draw(Painter &painter) override;

        void setPos(double new_x, double new_y) override;

        void setSize(double new_width, double new_height) override;

        double getArea() const override;

        std::array<PointF, 3> getPoints() const;

        bool Touch(int mx, int my) const override;

        std::shared_ptr<Shape> Clone() const override;
    };

} // shape

#endif //PAINTAPP_TRIANGLE_H
