#include <iostream>
#include "plugin/registry.h"

int main() {
    auto shape = ShapeFactory::instance().createShape("Circle");
    if (shape)
        std::cout << "shape created" << std::endl;
    else
        std::cout << "shape not found" << std::endl;
    return 0;
}