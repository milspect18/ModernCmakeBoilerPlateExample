// Main diver app code
#include "Utilities.hpp"
#include <iostream>

int main(int argc, const char *argv[]) {
    ExampleLib::EnhancedString myString("the Price family!");

    ExampleLib::sayHello(myString.lowercased());
}