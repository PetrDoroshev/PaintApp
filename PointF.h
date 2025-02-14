#ifndef PAINTAPP_POINTF_H
#define PAINTAPP_POINTF_H

struct PointF {

    double x;
    double y;

    PointF(double x, double y) : x(x), y(y) {};
    PointF() { x = 0.0; y = 0.0; };

};

#endif