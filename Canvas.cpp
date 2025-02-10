#include "Canvas.h"


void Canvas::Draw(Painter& painter) const {

    if (!shapes.empty()) {

        for (auto shape : shapes) {
            shape->Draw(painter);
        }
    }
}

void Canvas::Add(std::shared_ptr<shape::Shape> shape) {

    if (shape) {
        shapes.push_back(shape);
    }
}

std::optional<std::shared_ptr<shape::Shape>> Canvas::getShape(uint32_t x, uint32_t y) const {

    double min_area = width * height;
    std::shared_ptr<shape::Shape> min_area_shape = nullptr;

    for (auto shape: shapes) {

        if (shape->Touch(x, y)) {

            if (shape->getArea() < min_area) {
                min_area = shape->getArea();
                min_area_shape = shape;
            }
        }
    }

    if (min_area_shape) return min_area_shape;

    return {};
    
}

void Canvas::deleteShape(std::shared_ptr<shape::Shape> shape_to_delete) {

    for (auto it = shapes.begin(); it != shapes.end(); it++) {
        
        if (*it == shape_to_delete) {
            shapes.erase(it);
            break;
        }
    }
}



 size_t Canvas::getShapesNumber() const {
    return shapes.size();
}
