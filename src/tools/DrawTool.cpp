#include "DrawTool.h"

template<class ShapeType>
DrawTool<ShapeType>::DrawTool(Canvas *canvas, CommandManager *commandManager): Tool(canvas, commandManager) {

    this->shape_factory = new shape::ShapeFactory<ShapeType>();
}

template<class ShapeType>
DrawTool<ShapeType>::DrawTool(Canvas *canvas, CommandManager *commandManager, ShapeType shape_prototype):
    Tool(canvas, commandManager) {

    this->shape_factory = new PrototypeShapeFactory<ShapeType>(shape_prototype);
}

template<class ShapeType>
void DrawTool<ShapeType>::onMousePress(QMouseEvent *event) {

    if (event->button() == Qt::MouseButton::LeftButton) {

        press_x = event->pos().x();
        press_y = event->pos().y();

        begin_draw = true;
    }
}

template<class ShapeType>
void DrawTool<ShapeType>::onMouseMove(QMouseEvent *event) {

    double width = event->pos().x() - press_x;
    double height = event->pos().y() - press_y;

    if (width == 0 || height == 0) {
        return;
    }

    if (begin_draw) {
        commandManager->ExecuteCommand(new DrawCommand(canvas, shape_factory));
        begin_draw = false;
    }

    
    auto shape = *(canvas->end() - 1);

    shape->setPos(std::min(press_x, event->pos().x()), std::min(press_y, event->pos().y()));
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

