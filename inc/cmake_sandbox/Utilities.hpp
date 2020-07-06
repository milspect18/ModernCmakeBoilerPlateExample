// Example Library Code

#ifndef EXAMPLE_LIB_HPP
#define EXAMPLE_LIB_HPP

#include <string>

namespace ExampleLib {
    void sayHello(std::string from);

    class EnhancedString : public std::string {
    public:
        EnhancedString(const char *initString) : std::string(initString) {}
        std::string lowercased();
    };
} // namespace ExampleLib

#endif
