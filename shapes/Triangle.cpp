#include "Triangle.h"

namespace shape {

    void Triangle::computePoints() {
        
        points[0] = PointF(x, y + height);
        points[1] = PointF(x + width / 2, y);
        points[2] = PointF(x + width, y + height);

    }

    Triangle::Triangle(double x, double y, double width, double height, const Color& outlineColor) : Shape(x, y, width, height, outlineColor) { computePoints(); }

    Triangle::Triangle(const Triangle& triangle) : Shape(triangle) { computePoints(); }

    Triangle::Triangle() : Shape() { computePoints(); }

    void Triangle::Draw(Painter& painter) {
       
        painter.DrawTriangle(*this);
    }

    void Triangle::setPos(double new_x, double new_y)
    {   
        
        Shape::setPos(new_x, new_y);

    }

    void Triangle::setSize(double new_width, double new_height)
    {  
       
        /*if (new_height * height < 0) {

            double y_ = y + height / 2; 
            for (auto& point : points) {

                point.y = 2 * y_ - point.y;
            }
        }
        
        for (auto& point : points) {
            point.x = x + (point.x - x) * (new_width / width);
            point.y = y + (point.y - y) * (new_height / height);
        }*/

        Shape::setSize(new_width, new_height);
    }

    double Triangle::getArea() const {
        return height * width / 2.0;
    }

    std::array<PointF, 3> Triangle::getPoints() const {
        return points;
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