#ifndef PAINTAPP_PAINTER_H
#define PAINTAPP_PAINTER_H

#include "PainterImpl.h"
#include "../Color.h"



class Painter {

private:
    PainterImpl* painter_impl;

public:
    Painter() {};
    Painter(PainterImpl* painter_impl): painter_impl(painter_impl) {};

    PainterImpl* GetPainterImlp();
    void SetPainterImpl(PainterImpl* painter_impl);

    void DrawRect(const shape::Rectangle& rect);
    void DrawEllipse(const shape::Ellipse& ellipse);
    void DrawTriangle(const shape::Triangle& triangle);

};

#endif