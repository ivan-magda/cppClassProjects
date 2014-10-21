#include <iostream>
#include "Fraction.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Fraction frac2 = Fraction(12, 32);
    cout << endl;
    frac2.printFraction();


    cout << endl;
    frac2.changeToIrreducible();
    cout << endl;
    frac2.printFraction();
    cout << endl;
    
    return 0;
}
