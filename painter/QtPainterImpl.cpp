#include "QtPainterImpl.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Triangle.h"


void QtPainterImpl::DrawRect(const shape::Rectangle& rect) {

    QPainter painter(context);
    QPen pen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin);
    QRectF q_rect = QRectF(rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());

    painter.setPen(pen);
    painter.drawRect(q_rect);

    auto fill_color = rect.getFillColor();
    painter.fillRect(q_rect, QColor(fill_color.red, fill_color.green, fill_color.blue, fill_color.alpha));

}

void QtPainterImpl::DrawEllipse(const shape::Ellipse& ellipse) {

    QPainter painter(context);
    QPen pen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin);
    painter.setPen(pen);
    painter.drawEllipse(QRectF(ellipse.getX(), ellipse.getY(), ellipse.getWidth(), ellipse.getHeight()));

   

}

void QtPainterImpl::DrawPoly(const std::vector<PointF>& points){
    
    QPainter painter(context);
    QPen pen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin);
    painter.setPen(pen);
    
    
    QList<QPointF> q_points(points.size());
    for (int i = 0; i < points.size(); i++) {
        q_points[i] = QPointF(points[i].x, points[i].y);
    }

    painter.drawConvexPolygon(QPolygonF(q_points));

}
