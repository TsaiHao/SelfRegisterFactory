#include "registry.h"

std::unique_ptr<Shape> ShapeFactory::createShape(std::string_view name) {
    auto it = m_shapes.find(std::string(name));
    if (it != m_shapes.end()) {
        return it->second();
    }
    return nullptr;
}

void ShapeFactory::registerShape(std::string_view name, const ShapeFactory::CreateFunc &func) {
    m_shapes[std::string(name)] = func;
}
