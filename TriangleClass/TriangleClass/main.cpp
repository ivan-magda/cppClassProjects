#include <iostream>
#include <cmath>

using namespace std;


class Triangle {
private:
        //поля класса, стороны треугольника
    float a;
    float b;
    float c;

public:
        //констуруктор поумолчанию
    Triangle() {
        a = 0;
        b = 0;
        c = 0;
    }

        //конструктор с параметрами, параметры - длины сторон
    Triangle(float sideAlenght, float sideBlenght, float sideClenght) {
        a = sideAlenght;
        b = sideBlenght;
        c = sideClenght;
    }

        //деструктор
    ~Triangle() {
        cout << "Destructor has execute" << endl;
    }

    float perimetr() {
        return (a + b + c);
    }

    float square() {
        float semiPerimetr = perimetr() / 2.0;
        float square = sqrt(semiPerimetr * (semiPerimetr - a)
                                         * (semiPerimetr - b)
                                         * (semiPerimetr - c));
        if (!(square > 0)) {
            cout << "Такого треугольника не существует!!!\n";
            return 0;
        }
        return square;
    }
};

int main(int argc, const char * argv[]) {
    Triangle triangle1 = Triangle(2, 4, 7);

    cout << "Perimetr = " << triangle1.perimetr() << endl;
    cout << "Square   = " << triangle1.square()   << endl;


    Triangle triangle2 = Triangle(5, 7, 10);
    cout << "Square = "  << triangle2.square()    << endl;

    return 0;
}
