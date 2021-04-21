#include <iostream>
#include <memory>

void task2() {
    size_t N = 5;
    std::unique_ptr<std::unique_ptr<int[]>[]> matrix(std::make_unique<std::unique_ptr<int[]>[]>(N));
    for(size_t i = 0; i < N; i++) {
        matrix[i] = std::make_unique<int[]>(N);
    }

    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < N; j++) {
            matrix[i][j] = i + j;
        }
    }

    std::cout << "\nMATRIX\n";
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    size_t K = 3;
    std::unique_ptr<std::unique_ptr<int[]>[]> temp_matrix(std::make_unique<std::unique_ptr<int[]>[]>(N));
    for(size_t i = 0; i < N; i++) {
        temp_matrix[i] = std::make_unique<int[]>(N + K);
    }

    for(size_t i = 0; i < N; i++) {
        for(size_t j = K; j < N + K; j++) {
            temp_matrix[i][j] = matrix[i][j - K];
        }
    }

    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < K; j++) {
            temp_matrix[i][j] = 1;
        }
    }

    matrix = std::move(temp_matrix);

    std::cout << "\nRESULT\n";

    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < N + K; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
