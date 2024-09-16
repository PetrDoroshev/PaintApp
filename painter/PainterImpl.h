#ifndef PAINTAPP_PAINTERIMPL_H
#define PAINTAPP_PAINTERIMPL_H

namespace shape {
    class Rectangle;
    class Ellipse;
    class Triangle;
};


#include <QPainter>
#include <vector>
#include "../Color.h"
#include "../PointF.h"


class PainterImpl {

private:

public:

    PainterImpl() {};

    virtual void DrawRect(const shape::Rectangle& rect) = 0;
    virtual void DrawEllipse(const shape::Ellipse& ellipse) = 0;
    virtual void DrawPoly(const std::vector<PointF>& points) = 0;
};


#endif