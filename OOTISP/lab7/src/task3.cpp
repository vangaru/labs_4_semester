#include <iostream>
#include <memory>
#include <map>

void task3() {
    size_t N = 5;
    size_t M = 6;

    std::unique_ptr<std::unique_ptr<char[]>[]> matrix(std::make_unique<std::unique_ptr<char[]>[]>(N));
    for(size_t i = 0; i < N; i++) {
        matrix[i] = std::make_unique<char[]>(M);
    }

    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            matrix[i][j] = 'a' + i + j;
        }
    }

    std::cout << "\nMATRIX\n";

    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::map<char, size_t> chars_frequency;
    size_t unique_chars = 0;

    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            if(chars_frequency.count(matrix[i][j]) == 0) {
                chars_frequency[matrix[i][j]] = 0;
                unique_chars++;
            } else {
                chars_frequency[matrix[i][j]]++;
            }
        }
    }

    std::cout << "\nRESULT " << unique_chars;
}