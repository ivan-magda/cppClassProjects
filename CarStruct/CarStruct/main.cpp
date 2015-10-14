#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct Car {
    string brand; //бренд
    string countryOfOrigin; //страна производитель
    int yearOfCreation; //год производства
    int cost; //цена
};

    //Создание машины
void makeCar(Car &car, string brand, string countryOfOrigin, int yearOfCreation, int cost) {
    car.brand = brand;
    car.countryOfOrigin = countryOfOrigin;
    car.yearOfCreation = yearOfCreation;
    car.cost = cost;
}

    //форматированный вывод машины
ostream& operator << (ostream& os, const Car &car) {
    const int WIDTH = 15;

    os << left << "Brand:            " << setw(WIDTH) << right << car.brand           << endl
       << left << "Country Of Origin:" << setw(WIDTH) << right << car.countryOfOrigin << endl
       << left << "Year Of Creation: " << setw(WIDTH) << right << car.yearOfCreation  << endl
       << left << "Cost:             " << setw(WIDTH) << right << car.cost            << endl;

    return os;
}

    //Функции, которые используются для сортировки
    //В порядке возрастания
bool sortByBrand(Car car1, Car car2) {
    return (car1.brand < car2.brand);
}

bool sortByCountryOfOrigin(Car car1, Car car2) {
    return (car1.countryOfOrigin < car2.countryOfOrigin);
}

    //В порядке убывания
bool sortByYear(Car car1, Car car2) {
    return (car1.yearOfCreation > car2.yearOfCreation);
}

bool sortByCost(Car car1, Car car2) {
    return (car1.cost > car2.cost);
}

    //Вывод русских автомобилей, отсортированных по бренду
void printRuCars(Car *cars, const int size) {
    vector<Car> foundCars;
    foundCars.reserve(size/2);

    for (int i = 0; i < size; ++i) {
        if (cars[i].countryOfOrigin == "Russia") {
            foundCars.push_back(cars[i]);
        }
    }

    sort(foundCars.begin(), foundCars.end(), sortByBrand);

    for (vector<Car>::iterator it = foundCars.begin(); it != foundCars.end(); ++it) {
        cout << *it << endl;
    }
}

    //Функции для вывода всех автомобилей по разным параметрам(бренду, цене...)
void printByBrand(Car *cars, const int size) {
    vector<Car>foundCars;
    foundCars.reserve(size);

    for (int i = 0; i < size; ++i) {
        foundCars.push_back(cars[i]);
    }

    sort(foundCars.begin(), foundCars.end(), sortByBrand);

    for (vector<Car>::iterator it = foundCars.begin(); it != foundCars.end(); ++it) {
        cout << *it << endl;
    }
}

void printByCountry(Car *cars, const int size) {
    vector<Car>foundCars;
    foundCars.reserve(size);

    for (int i = 0; i < size; ++i) {
        foundCars.push_back(cars[i]);
    }

    sort(foundCars.begin(), foundCars.end(), sortByCountryOfOrigin);

    for (vector<Car>::iterator it = foundCars.begin(); it != foundCars.end(); ++it) {
        cout << *it << endl;
    }
}

void printByYear(Car *cars, const int size) {
    vector<Car>foundCars;
    foundCars.reserve(size);

    for (int i = 0; i < size; ++i) {
        foundCars.push_back(cars[i]);
    }

    sort(foundCars.begin(), foundCars.end(), sortByYear);

    for (vector<Car>::iterator it = foundCars.begin(); it != foundCars.end(); ++it) {
        cout << *it << endl;
    }
}

void printByCost(Car *cars, const int size) {
    vector<Car>foundCars;
    foundCars.reserve(size);

    for (int i = 0; i < size; ++i) {
        foundCars.push_back(cars[i]);
    }

    sort(foundCars.begin(), foundCars.end(), sortByCost);

    for (vector<Car>::iterator it = foundCars.begin(); it != foundCars.end(); ++it) {
        cout << *it << endl;
    }
}

void printByBrandAndYear(Car *cars, const int size) {
    vector<Car>foundCars;
    foundCars.reserve(size);

    for (int i = 0; i < size; ++i) {
        foundCars.push_back(cars[i]);
    }

    sort(foundCars.begin(), foundCars.end(), sortByBrand);
    sort(foundCars.begin(), foundCars.end(), sortByYear);

    for (vector<Car>::iterator it = foundCars.begin(); it != foundCars.end(); ++it) {
        cout << *it << endl;
    }
}

int main(int argc, const char * argv[]) {
    const int size = 10;

    Car cars[size];

    makeCar(cars[0], "Acura",        "Japan",          2014, 5000000);
    makeCar(cars[1], "Alfa Romeo",   "Italy",          2013, 4500000);
    makeCar(cars[2], "Aston Martin", "United Kingdom", 2014, 15000000);
    makeCar(cars[3], "Audi",         "Germany",        2014, 18000000);
    makeCar(cars[4], "Bentley",      "United Kingdom", 2015, 21000000);
    makeCar(cars[5], "BMW",          "Germany",        2015, 16000000);
    makeCar(cars[6], "Bugatti",      "France",         2010, 50000000);
    makeCar(cars[7], "Жигули",       "Russia",         1998, 1000000);
    makeCar(cars[8], "Нива",         "Russia",         2000, 1200000);
    makeCar(cars[9], "Волга",        "Russia",         2002, 2000000);

    int item = 0;
    do {
        cout << "1. Вывести русские автомобили.\n"
             << "2. Вывести автомобили по дате выпуска.\n"
             << "3. Вывести автомобили по марке.\n"
             << "4. Вывести автомобили по стране.\n"
             << "5. Вывести автомобили по цене.\n"
             << "6. Вывести автомобили по марке и дате выпуска.\n"
             << "7. Выход\n";

        cin >> item;
        switch (item) {
            case 1: {
                printRuCars(cars, size);
                break;
            }
            case 2: {
                printByYear(cars, size);
                break;
            }
            case 3:
                printByBrand(cars, size);
                break;
            case 4:
                printByCountry(cars, size);
                break;
            case 5:
                printByCost(cars, size);
                break;
            case 6:
                printByBrandAndYear(cars, size);
                break;
            case 7:
                return 0;
            default:
                continue;
        }
    } while (item != 7);

    return 0;
}
