#include <iostream>
#include "Fraction.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Fraction frac1;
    frac1.printFraction();
    
    
    Fraction frac2 = Fraction(12, 32);
    cout << endl;
    frac2.printFraction();
    
    frac2.changeToIrreducible();
    cout << endl;
    frac2.printFraction();
    
    return 0;
}
