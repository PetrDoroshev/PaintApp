#include "DrawCommand.h"

DrawCommand::DrawCommand(Canvas* canvas, shape::Factory* shapeFactory) : canvas(canvas), shape_factory(shapeFactory) {}

void DrawCommand::Execute() {
    created_shape = std::shared_ptr<shape::Shape>(shape_factory->Create());
    canvas->Add(created_shape);
}

void DrawCommand::unExecute() {

   canvas->deleteShape(created_shape);
}
DrawCommand::~DrawCommand() = default;

