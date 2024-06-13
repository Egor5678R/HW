#include <iostream>

void evendigits(long long n, int &ans) {
    if (n == 0) return;
    if ((n % 10) % 2 == 0) ++ans;
    evendigits(n / 10, ans);
}

int main() {
    long long n = 9223372036854775806;
    int ans;
    std::cout << "Введите ans: ";
    std::cin >> ans;

    evendigits(n, ans);

    std::cout << "Вывод: " << ans << std::endl;
}
