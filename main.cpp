#include <iostream>
#include <dlfcn.h>
#include "plugin/registry.h"

int main() {
    void* lib = dlopen("libcircle_shape.dylib", RTLD_LAZY);
    if (!lib) {
        std::cout << "lib not found" << std::endl;
        return 0;
    }

    auto shape = ShapeFactory::instance().createShape("Circle");
    if (shape)
        std::cout << "shape created" << std::endl;
    else
        std::cout << "shape not found" << std::endl;
    return 0;
}