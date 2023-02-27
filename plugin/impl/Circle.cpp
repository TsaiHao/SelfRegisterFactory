#include "shape.h"
#include "registry.h"

class Circle: public Shape {
public:
    Circle() = default;

    double area() const override;

private:
    double m_radius = 0;

    static bool m_registered;
};

bool Circle::m_registered = registerShape<Circle>("Circle");

double Circle::area() const {
    return 3.14 * m_radius * m_radius;
}