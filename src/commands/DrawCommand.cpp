#include "DrawCommand.h"

DrawCommand::DrawCommand(Canvas& canvas, std::shared_ptr<shape::Shape> createdShape) :
    canvas(canvas), created_shape(createdShape) {}

void DrawCommand::Execute() {
    canvas.Add(created_shape);
}

void DrawCommand::unExecute() {
   canvas.deleteShape(created_shape);
}

DrawCommand::~DrawCommand() = default;
