#ifndef PAINTAPP_SHAPEGROUP_H
#define PAINTAPP_SHAPEGROUP_H

#include "Shape.h"

namespace shape {
    class ShapeGroup : public Shape {
    public:
        ShapeGroup() = default;

        ShapeGroup(const ShapeGroup& shapeGroup);

        void Draw(Painter &painter) const override;

        void Add(std::shared_ptr<Shape> shape);

        void Update();

        void Clear();

        std::shared_ptr<Shape> Clone() const override;

        void setPos(double new_x, double new_y) override;
        
        void setSize(double new_width, double new_height) override;

    private:
        std::vector<std::shared_ptr<Shape>> shapes;
    };
}

#endif //PAINTAPP_SHAPEGROUP_H
