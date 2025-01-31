#ifndef PAINTAPP_MANIPULATORTOOL_H
#define PAINTAPP_MANIPULATORTOOL_H

#include "Tool.h"
#include "../commands/MoveCommand.h"
#include "../commands/ResizeCommand.h"
#include "../shapes/ShapeGroup.h"

class ManipulatorTool: public Tool {

private:

    int prev_x = 0;
    int prev_y = 0;
    bool is_click = true;
    bool ctrl_pressed = false;
    shape::Manipulator manipulator = shape::Manipulator(nullptr);
    shape::ShapeGroup shape_group = shape::ShapeGroup();

public:

    explicit ManipulatorTool(PaintSurface* paintSurface, CommandManager* commandManager);

    void onMousePress(QMouseEvent *event) override;
    void onMouseMove(QMouseEvent *event) override;
    void onMouseRelease(QMouseEvent *event) override;
    void onKeyPress(QKeyEvent *event) override;

    void onKeyRelease(QKeyEvent *event) override;

};


#endif //PAINTAPP_MANIPULATORTOOL_H
