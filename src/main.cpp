#include <iostream>
#include "engine/feature.h"

int main() {
    Feature feature;

    feature.setAttribute("height", 12.5);
    feature.setAttribute("name", std::string("Building A"));
    feature.setAttribute("floors", 3);

    auto heightOpt = feature.getAttribute("name");
    if (!heightOpt) return 0; // exit if no height

    auto& height = *heightOpt;
    std::visit([](auto&& value) {
        std::cout << "name: " << value << std::endl;
    }, height);

    // std::cout << "Attribute count: " << feature.attributeCount() << "\n";
    return 0;
}