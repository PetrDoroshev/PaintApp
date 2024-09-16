#ifndef PAINTAPP_QTPAINTERIMPL_H
#define PAINTAPP_QTPAINTERIMPL_H

#include "PainterImpl.h"
#include <QWidget>

class QtPainterImpl : public PainterImpl {

public:

    QtPainterImpl() {};
    QtPainterImpl(QWidget* context) : context(context) {};

    void DrawRect(const shape::Rectangle& rect) override;
    void DrawEllipse(const shape::Ellipse& ellipse) override;
    void DrawPoly(const std::vector<PointF>& points) override;


private:
    QWidget* context;

};

#endif