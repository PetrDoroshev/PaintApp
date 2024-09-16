#include "DrawTool.h"

template<class ShapeType>
DrawTool<ShapeType>::DrawTool(PaintSurface *paintSurface, CommandManager *commandManager):
    Tool(paintSurface, commandManager) {

    this->shape_factory = new shape::ShapeFactory<ShapeType>();
}

template<class ShapeType>
DrawTool<ShapeType>::DrawTool(PaintSurface *paintSurface, CommandManager *commandManager, ShapeType shape_prototype):
    Tool(paintSurface, commandManager) {

    this->shape_factory = new PrototypeShapeFactory<ShapeType>(shape_prototype);
}

template<class ShapeType>
void DrawTool<ShapeType>::onMousePress(QMouseEvent *event) {

    if (event->button() == Qt::MouseButton::LeftButton) {

        first_x = event->pos().x();
        first_y = event->pos().y();

        begin_draw = true;
    }
}

template<class ShapeType>
void DrawTool<ShapeType>::onMouseMove(QMouseEvent *event) {

    double width = abs(event->pos().x() - first_x);
    double height = abs(event->pos().y() - first_y);

    if (width == 0 || height == 0) {
        return;
    }

    if (begin_draw) {
        commandManager->ExecuteCommand(new DrawCommand(paintSurface->shapes, shape_factory));
        begin_draw = false;
    }

    shape::Shape* shape = *(paintSurface->shapes.end() - 1);

    shape->setPos(std::min(first_x, event->pos().x()), std::min(first_y, event->pos().y()));
    shape->setSize(width, height);

}

template<class ShapeType>
void DrawTool<ShapeType>::onMouseRelease(QMouseEvent *event) {

}

template<class ShapeType>
void DrawTool<ShapeType>::onKeyPress(QKeyEvent *event) {

}

template<class ShapeType>
void DrawTool<ShapeType>::onKeyRelease(QKeyEvent *event) {

}

