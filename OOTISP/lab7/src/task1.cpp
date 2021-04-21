#include "task1.h"
#include <cmath>
#include <iostream>
#include <memory>

void task1() {
    size_t size = 15;
    std::unique_ptr<int []> arr = std::make_unique<int []>(size);
    for(int i = 0; i < size; i++) {
        arr[i] = i;
    }

    std::cout << "\nARRAY\n";
    for(size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    size_t new_arr_size = std::ceil((static_cast<float>(size) / 2));
    std::unique_ptr<int []> new_arr = std::make_unique<int []>(new_arr_size);

    for(size_t i = 0, j = 0; i < size; i += 2) {
        new_arr[j] = arr[i];
        j++;
    }

    arr = std::move(new_arr);

    std::cout << "\nRESULT\n";

    for(size_t i = 0; i < new_arr_size; i++) {
        std::cout << arr[i]  << " ";
    }
}