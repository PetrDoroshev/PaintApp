#include "ShapeGroup.h"
#include <iostream>
#include <limits>

void shape::ShapeGroup::Draw(Painter& painter) const {

    for (auto shape: shapes) {
        shape->Draw(painter);
    }
}

void shape::ShapeGroup::Add(std::shared_ptr<shape::Shape> shape) {

    if (shape.get() == this) {
        return;
    }
    if (shape == nullptr) {
        return;
    }
    if (std::find(shapes.begin(), shapes.end(), shape) != shapes.end()) {
        return;
    }

    shapes.push_back(shape);
    this->Update();
}

void shape::ShapeGroup::Update() {


    auto [min_x_it, max_x_it] = std::minmax_element(shapes.begin(), shapes.end(),
                                                          [](std::shared_ptr<Shape> s1, std::shared_ptr<Shape> s2) {
        return s1->getX() < s2->getX();
    });

    auto [min_y_it, max_y_it] = std::minmax_element(shapes.begin(), shapes.end(),
                                  [](std::shared_ptr<Shape> s1, std::shared_ptr<Shape> s2) {
        return s1->getY() < s2->getY();
    });

    auto max_width_shape = *(std::max_element(shapes.begin(), shapes.end(), [](std::shared_ptr<Shape> s1, std::shared_ptr<Shape> s2) {
        return s1->getWidth() < s2->getWidth();
    }));

    auto max_height_shape = *(std::max_element(shapes.begin(), shapes.end(), [](std::shared_ptr<Shape> s1, std::shared_ptr<Shape> s2) {
        return s1->getHeight() < s2->getHeight();
    }));

    auto min_x_shape = *min_x_it;
    auto max_x_shape = *max_x_it;

    auto min_y_shape = *min_y_it;
    auto max_y_shape = *max_y_it;

    x = min_x_shape->getX();
    y = min_y_shape->getY();

    width = std::max(max_x_shape->getX() + max_x_shape->getWidth(), max_width_shape->getX() + max_width_shape->getWidth()) - min_x_shape->getX(),
    height = std::max(max_y_shape->getY() + max_y_shape->getHeight(), max_height_shape->getY() + max_height_shape->getHeight()) - min_y_shape->getY();

}

void shape::ShapeGroup::Clear() {
    shapes.clear();
}

std::shared_ptr<shape::Shape> shape::ShapeGroup::Clone() const {

    return std::shared_ptr<shape::Shape> (new ShapeGroup(*this));
}

shape::ShapeGroup::ShapeGroup(const shape::ShapeGroup &shapeGroup) : Shape(shapeGroup) {

    for (auto shape: shapeGroup.shapes) {
        this->Add(shape->Clone());
    }

}

void shape::ShapeGroup::setPos(double new_x, double new_y) {

    for (auto shape: shapes) {
        shape->setPos(shape->getX() + new_x - x, shape->getY() + new_y - y);
    }
    Shape::setPos(new_x, new_y);
}

void shape::ShapeGroup::setSize(double new_width, double new_height) {

    //new_width = fmax(10.0, new_width);
    //new_height = fmax(10.0, new_height);

    std::cout << new_width << ", " << new_height << std::endl;

    double scale_x = new_width / width;
    double scale_y = new_height / height;

    for (auto shape: shapes) {

        shape->setSize(shape->getWidth() * scale_x, shape->getHeight() * scale_y);
        shape->setPos(x + (shape->getX() - x) * scale_x, y + (shape->getY() - y) * scale_y);
    }

    Shape::setSize(new_width, new_height);
}


