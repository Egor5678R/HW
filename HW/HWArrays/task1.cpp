#include <iostream>
#include <vector>

void swapvec(std::vector<int> &vec, int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::swap(vec[i], arr[i]);
    }
}

int main() {
    std::vector<int> a = {1, 5, 3, 8 };
    int b[] = {1, 4, 3, 2};
    int size = 4;

    swapvec(a, b, size);

    for (int i = 0; i < size; ++i) {
        std::cout << a[i];
    }
    std::cout << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << b[i];
    }
}
