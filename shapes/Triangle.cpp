#include "Triangle.h"

namespace shape {
    Triangle::Triangle(double x, double y, double width, double height, const Color &outlineColor) {}

    Triangle::Triangle() = default;

    void Triangle::Draw(Painter& painter) const {
        /*
        QPen pen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin);
        painter.setPen(pen);

        QPointF points[3] = {
                QPointF(x, y + height),
                QPointF(x + width / 2, y),
                QPointF(x + width, y + height)
        };

        painter.drawPolygon(points, 3);
        */

        painter.DrawTriangle(*this);
    }

    double Triangle::getArea() const {
        return height * width / 2.0;
    }

    bool Triangle::Touch(int mx, int my) const {

        double x1 = x, y1 = y + height;
        double x2 = x + width / 2.0, y2 = y;
        double x3 = x + width, y3 = y1;

        return (my < y + height &&
                my - y1 > ((y2 - y1) / (x2 - x1)) * (mx - x1) &&
                my - y3 > ((y2 - y3) / (x2 - x3)) * (mx - x3));

    }

    std::shared_ptr<Shape> Triangle::Clone() const {
        return std::shared_ptr<Shape> (new Triangle(*this));
    }
} // shape