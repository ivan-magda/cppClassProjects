#include <iostream>
#include "FractionOperations.h"

using namespace std;

int main(int argc, const char * argv[]) {

    FractionOperations multiplication1(2, 3);
    FractionOperations multiplication2(3, 5);
    FractionOperations resultOfMultiplication = multiplication1 * multiplication2; // 6/15
    resultOfMultiplication.changeToIrreducible(); // 2/5

    resultOfMultiplication.printFraction();
    cout << endl;


    FractionOperations division1(4, 7);
    FractionOperations division2(5, 8);
    FractionOperations resultOfDivision = division1 / division2; // 32/35
    resultOfDivision.changeToIrreducible();

    cout << endl;
    resultOfDivision.printFraction();
    cout << endl;


    return 0;
}
