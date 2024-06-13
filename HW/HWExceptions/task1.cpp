#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class Shop {
public:
    void addProduct(const std::string& article, int quantity) {
        if (quantity < 0) {
            throw std::invalid_argument("Количество не может быть отрицательным.");
        }
        inventory[article] += quantity;
    }

    void addToCart(const std::string& article, int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Количество должно быть положительным.");
        }
        if (inventory.find(article) == inventory.end()) {
            throw std::invalid_argument("Товар не найден в инвентаре.");
        }
        if (inventory[article] < quantity) {
            throw std::runtime_error("Недостаточно товаров на складе.");
        }
        cart[article] += quantity;
        inventory[article] -= quantity;
    }

    void removeFromCart(const std::string& article, int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Количество должно быть положительным.");
        }
        if (cart.find(article) == cart.end() || cart[article] < quantity) {
            throw std::runtime_error("Недостаточно товаров в корзине.");
        }
        cart[article] -= quantity;
        inventory[article] += quantity;
        if (cart[article] == 0) {
            cart.erase(article);
        }
    }

    void printInventory() const {
        std::cout << "Инвентарь:\n";
        for (const auto& item : inventory) {
            std::cout << "Группа: " << item.first << ", Количество: " << item.second << "\n";
        }
    }

    void printCart() const {
        std::cout << "Корзина:\n";
        for (const auto& item : cart) {
            std::cout << "Группа: " << item.first << ", Количество: " << item.second << "\n";
        }
    }

private:
    std::map<std::string, int> inventory;
    std::map<std::string, int> cart;
};

int main() {
    Shop shop;
    shop.addProduct("Вещь1", 10);
    shop.addProduct("Вещь2", 20);

    shop.printInventory();

    try {
        shop.addToCart("Вещь1", 5);
        shop.addToCart("Вещь2", 10);
        shop.removeFromCart("Вещь1", 2);
        shop.printCart();
        shop.printInventory();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
