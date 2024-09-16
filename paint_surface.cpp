#include <QWidget>
#include <QMouseEvent>
#include <iostream>
#include "paint_surface.h"
#include "shapes/Rectangle.h"
#include "tools/DrawTool.h"



PaintSurface::PaintSurface(QWidget *parent): QWidget(parent) {

    setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    painter = Painter(new QtPainterImpl(this));
}

void PaintSurface::paintEvent(QPaintEvent *event) {

    QPainter qt_painter(this);
    //painter.setRenderHint(QPainter::Antialiasing, true);

    qt_painter.fillRect(rect(), QBrush(Qt::white));
    
    for (auto shape: shapes) {
        shape->Draw(painter);
    }
    manipulator.Draw(painter);

}

void PaintSurface::mousePressEvent(QMouseEvent *event) {
    current_tool->onMousePress(event);
    repaint();

}

void PaintSurface::mouseReleaseEvent(QMouseEvent* event) {
    current_tool->onMouseRelease(event);
    repaint();
}

void PaintSurface::mouseMoveEvent(QMouseEvent *event) {
    current_tool->onMouseMove(event);
    repaint();
}

void PaintSurface::keyPressEvent(QKeyEvent *event) {
    current_tool->onKeyPress(event);

    QApplication::sendEvent(parent(), event);
    repaint();
}

void PaintSurface::keyReleaseEvent(QKeyEvent *event) {
    current_tool->onKeyRelease(event);
    repaint();
}





