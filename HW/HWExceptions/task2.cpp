#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Fish {};
class Boot {};

void throwFishCaught() {
    throw Fish();
}

void throwBootCaught() {
    throw Boot();
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int fishSector = rand() % 9;
    int bootSectors[3];
    for (int i = 0; i < 3; ++i) {
        do {
            bootSectors[i] = rand() % 9;
        } while (bootSectors[i] == fishSector || (i > 0 && bootSectors[i] == bootSectors[i - 1]));
    }

    int attempts = 0;
    while (true) {
        int guess;
        std::cout << "Введите номер сектора (0-8): ";
        std::cin >> guess;

        if (guess < 0 || guess > 8) {
            std::cerr << "Неверный номер сектора. Попробуйте еще раз.\n";
            continue;
        }

        ++attempts;

        if (guess == fishSector) {
            throwFishCaught();
        }

        for (int i = 0; i < 3; ++i) {
            if (guess == bootSectors[i]) {
                throwBootCaught();
            }
        }

        std::cout << "Рыбы здесь нет. Попробуйте еще раз.\n";
    }

    try {
    
    } catch (const Fish&) {
        std::cout << "Вы поймали рыбу в " << attempts << " attempts!\n";
    } catch (const Boot&) {
        std::cout << "Ты поймал ботинок! Игра окончена.\n";
    }
}
