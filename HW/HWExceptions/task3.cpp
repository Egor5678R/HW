#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename KeyType, typename ValueType>
struct KeyValuePair {
    KeyType key;
    ValueType value;

    KeyValuePair(KeyType k, ValueType v) : key(k), value(v) {}
};

template <typename KeyType, typename ValueType>
class Registry {
private:
    std::vector<KeyValuePair<KeyType, ValueType>> data;

public:
    void add(KeyType key, ValueType value) {
        data.emplace_back(key, value);
    }

    void remove(KeyType key) {
        data.erase(std::remove_if(data.begin(), data.end(), 
            [&key](const KeyValuePair<KeyType, ValueType>& pair) { return pair.key == key; }), data.end());
    }

    void print() const {
        for (const auto& pair : data) {
            std::cout << "Ключ: " << pair.key << ", Значение: " << pair.value << std::endl;
        }
    }

    void find(KeyType key) const {
        for (const auto& pair : data) {
            if (pair.key == key) {
                std::cout << "Найдено - Ключ: " << pair.key << ", Значение: " << pair.value << std::endl;
            }
        }
    }
};

template <typename KeyType, typename ValueType>
void processCommands() {
    Registry<KeyType, ValueType> registry;
    std::string command;

    while (true) {
        std::cout << "Введите команду (add, remove, print, find, exit): ";
        std::cin >> command;

        if (command == "add") {
            KeyType key;
            ValueType value;
            std::cout << "Введите ключ и значение: ";
            std::cin >> key >> value;
            registry.add(key, value);
        } else if (command == "remove") {
            KeyType key;
            std::cout << "Введите ключ для удаления: ";
            std::cin >> key;
            registry.remove(key);
        } else if (command == "print") {
            registry.print();
        } else if (command == "find") {
            KeyType key;
            std::cout << "Введите ключ, чтобы найти: ";
            std::cin >> key;
            registry.find(key);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Неизвестная команда!" << std::endl;
        }
    }
}

int main() {
    std::string type;
    std::cout << "Выберите тип ключа (int, double, string): ";
    std::cin >> type;

    if (type == "int") {
        processCommands<int, std::string>();
    } else if (type == "double") {
        processCommands<double, std::string>();
    } else if (type == "string") {
        processCommands<std::string, std::string>();
    } else {
        std::cout << "Неподдерживаемый тип ключа!" << std::endl;
    }

    return 0;
}