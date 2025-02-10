#ifndef PAINTAPP_PAINT_SURFACE_H
#define PAINTAPP_PAINT_SURFACE_H

#include <QApplication>
#include <QPainter>
#include <QWidget>
#include <QMenu>
#include <QImage>
#include <QMoveEvent>
#include "shapes/Shape.h"
#include "shapes/factory/Factory.h"
#include "shapes/Manipulator.h"
#include "tools/ManipulatorTool.h"
#include "painter/Painter.h"
#include "painter/QtPainterImpl.h"
#include "Canvas.h"

class Tool;

class PaintSurface: public QWidget {

    Q_OBJECT;

private:


public:
    explicit PaintSurface(QWidget* parent = nullptr);

    Canvas canvas;
    QColor outline_color;
    QColor fill_color;
    Tool* current_tool = nullptr;
    Painter painter;

    void Update() { repaint(); }


protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
};


#endif //PAINTAPP_PAINT_SURFACE_H
