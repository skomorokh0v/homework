#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <locale>  // Для установки локали
#include <codecvt> // Для конвертации кодировок

struct Car {
    std::string name;        // Название машины
    std::string model;       // Модель
    int maxSpeed;            // Максимальная скорость
    std::string creationDate; // Дата создания

    void display() const {
        std::cout << "Название машины: " << name << std::endl
            << "Модель: " << model << std::endl
            << "Максимальная скорость: " << maxSpeed << " км/ч" << std::endl
            << "Год создания: " << creationDate << std::endl
            << "-----------------------------" << std::endl; // Разделитель между машинами
    }
};

int main() {
    // Установка локали для поддержки русских символов
    std::locale::global(std::locale("ru_RU.UTF-8")); // Для Linux/macOS
    // setlocale(LC_ALL, "Russian"); // Для Windows

    std::ifstream inputFile("cars.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    std::vector<Car> cars;  // Вектор для хранения данных о машинах
    std::string line;

    // Чтение данных из файла
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        Car car;

        // Чтение данных из строки
        if (iss >> car.name >> car.model >> car.maxSpeed >> car.creationDate) {
            cars.push_back(car);
        }
        else {
            std::cerr << "Ошибка чтения строки: " << line << std::endl;
        }
    }

    inputFile.close(); // Закрытие файла

    // Вывод информации о машинах
    std::cout << "Данные о машинах:" << std::endl;
    for (const auto& car : cars) {
        car.display();
    }

    return 0;
}
