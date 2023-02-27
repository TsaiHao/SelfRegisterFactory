#pragma once

#include <string>
#include <memory>
#include <functional>
#include <unordered_map>

#include "shape.h"

class ShapeFactory {
public:
    using CreateFunc = std::function<std::unique_ptr<Shape>()>;

    static ShapeFactory& instance() {
        static ShapeFactory factory;
        return factory;
    }

    void registerShape(std::string_view name, const CreateFunc& func);

    std::unique_ptr<Shape> createShape(std::string_view name);
private:
    ShapeFactory() = default;
    ~ShapeFactory() = default;

    std::unordered_map<std::string, CreateFunc> m_shapes;
};

template <typename ShapeType>
bool registerShape(std::string_view name) {
    ShapeFactory::instance().registerShape(name, []() {
        return std::unique_ptr<Shape>(new ShapeType());
    });
    return true;
}