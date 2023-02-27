#ifndef GBU_SHAPE_H
#define GBU_SHAPE_H

class Shape {
public:
    virtual ~Shape() = default;

    virtual double area() const = 0;
};

#endif //GBU_SHAPE_H
