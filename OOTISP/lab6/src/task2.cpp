#include "task2.h"

void function() {
    throw(10);
}

void task2() {
    try {
        for (int i = 0; i < 10; i++) {
            if (i > 2) {
                if (i < 6) {
                    if (i > 3) {
                        if (i == 4) {
                            function();
                        }
                    }
                }
            }
        }
    }
    catch(int e) {
        std::cout << "\nexception is handled\n";
    }
}