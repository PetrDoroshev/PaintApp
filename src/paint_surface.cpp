#include <QWidget>
#include <QMouseEvent>
#include <iostream>
#include "paint_surface.h"
#include "shapes/Rectangle.h"
#include "tools/DrawTool.h"



PaintSurface::PaintSurface(QWidget *parent): QWidget(parent) {

    setFocusPolicy(Qt::FocusPolicy::StrongFocus);

    painter = Painter(new QtPainterImpl(this));
    canvas = Canvas(this->width(), this->height());
}

void PaintSurface::paintEvent(QPaintEvent *event) {

    QPainter qt_painter(this);
    qt_painter.fillRect(rect(), QBrush(Qt::white));
    
    canvas.Draw(painter);

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

void PaintSurface::resizeEvent(QResizeEvent* event)
{
    canvas.setWidth(event->size().width());
    canvas.setHeight(event->size().height());
}





