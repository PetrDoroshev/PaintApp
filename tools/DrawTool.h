#ifndef PAINTAPP_DRAWTOOL_H
#define PAINTAPP_DRAWTOOL_H

#include "Tool.h"
#include "../commands/DrawCommand.h"
#include "../shapes/factory/ShapeFactory.h"
#include "../shapes/factory/PrototypeShapeFactory.h"
#include "../paint_surface.h"

template<class ShapeType>
class DrawTool: public Tool {

private:
    shape::Factory* shape_factory = nullptr;
    int first_x = 0;
    int first_y = 0;
    int prev_x = 0;
    int prev_y = 0;
    bool begin_draw = false;

public:

    explicit DrawTool(PaintSurface *paintSurface, CommandManager *commandManager);
    DrawTool(PaintSurface *paintSurface, CommandManager *commandManager, ShapeType shape_prototype);

    void onMousePress(QMouseEvent *event) override;
    void onMouseMove(QMouseEvent *event) override;
    void onMouseRelease(QMouseEvent* event) override;
    void onKeyPress(QKeyEvent *event) override;
    void onKeyRelease(QKeyEvent *event) override;
};

#endif //PAINTAPP_DRAWTOOL_H
