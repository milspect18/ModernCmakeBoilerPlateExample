// Exmple lib
#include "Utilities.hpp"
#include <iostream>

namespace ExampleLib {
    void sayHello(std::string from) {
        std::cout << "Hello from " << from << "\n";
    }

    std::string EnhancedString::lowercased() {
        std::string retStr = "";

        for (auto c : *this) {
            retStr += tolower(c);
        }

        return retStr;
    }
} // namespace ExampleLib
