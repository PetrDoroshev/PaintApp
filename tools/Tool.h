#ifndef PAINTAPP_TOOL_H
#define PAINTAPP_TOOL_H

#include <QMouseEvent>
#include "../Canvas.h"
#include "../shapes/Shape.h"
#include "../commands/CommandManager.h"

class PaintSurface;

class Tool {

protected:
    Canvas* canvas = nullptr;
    CommandManager* commandManager = nullptr;

public:


    Tool(Canvas *canvas, CommandManager *commandManager) : canvas(canvas), commandManager(commandManager) {}

    virtual void onMousePress(QMouseEvent *event) = 0;
    virtual void onMouseMove(QMouseEvent *event) = 0;
    virtual void onMouseRelease(QMouseEvent* event) = 0;
    virtual void onKeyPress(QKeyEvent *event) = 0;
    virtual void onKeyRelease(QKeyEvent *event) = 0;
};

#endif //PAINTAPP_TOOL_H
