#include "task1.h"

void task1() {
    try {
        Person person("Bob", 12);
        throw(10);
    }
    catch(...) {
        std::cout << "Exception";
    }
}