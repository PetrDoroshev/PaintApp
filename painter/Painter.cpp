#include "Painter.h"
#include "../shapes/Triangle.h"



void Painter::DrawRect(const shape::Rectangle& rect) {
	painter_impl->DrawRect(rect);

}

void Painter::DrawEllipse(const shape::Ellipse& ellipse) {

	painter_impl->DrawEllipse(ellipse);

}

void Painter::DrawTriangle(const shape::Triangle& triangle) {
	
	auto x = triangle.getX();
	auto y = triangle.getY();

	auto width = triangle.getWidth();
	auto height = triangle.getHeight();

	std::vector<PointF> points = {
			   PointF(x, y + height),
			   PointF(x + width / 2, y),
			   PointF(x + width, y + height)
	};
	
	painter_impl->DrawPoly(points);
}



