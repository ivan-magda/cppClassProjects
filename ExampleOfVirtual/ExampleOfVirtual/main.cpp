#include "product.h"

int main() {
    Product* products[10];

    products[0] = new Computer(1, "ASUS", "ASUS K52N", 300, 3.5);
    products[1] = new Computer(2, "Dell", "Dell Inspiron One 2205", 500, 3.1);
    products[2] = new Computer(3, "SONY", "S1234", 160, 3.5);
    products[3] = new Printer(4, "HP", "HP-2342", true, Printer::LASER, "600dpi", "Do not cover");

    for (int i = 0; i < 4; ++i)
        cout << products[i]->getInfo() << endl;

    for (int i=0; i < 4; ++i)
        delete products[i];

    return 0;
}