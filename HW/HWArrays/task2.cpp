#include <iostream>

int waysToReachStep(int n, int k = 3) {
    if (n == 0) return 1;
    int ways = 0;
    for (int i = 1; i <= k; ++i) {
        if (n - i >= 0) ways += waysToReachStep(n - i, k);
    }
    return ways;
}

int main() { 
    int n;
    int k;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << "Введите k: ";
    std::cin >> k;

    std::cout <<  "Вывод: " << waysToReachStep(n, k) << std::endl;
}
