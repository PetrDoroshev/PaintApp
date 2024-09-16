#include "DrawCommand.h"

DrawCommand::DrawCommand(std::vector<shape::Shape*>& shapes, shape::Factory* shapeFactory) : shapes(shapes),
                                                                                              shape_factory(shapeFactory) {}

void DrawCommand::Execute() {
    created_shape = shape_factory->Create();
    shapes.push_back(created_shape);
}

void DrawCommand::unExecute() {

    auto shape_to_remove_it = std::find(shapes.begin(), shapes.end(), created_shape);
    shapes.erase(shape_to_remove_it);

    delete *(shape_to_remove_it);
}
DrawCommand::~DrawCommand() = default;

