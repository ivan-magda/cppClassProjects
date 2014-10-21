#include "Fraction.h"
#include <iostream>

using namespace std;

void Fraction::printFraction() const {
    cout << this->numerator <<
    endl << "-" <<
    endl << this->denominator;
}

int Fraction::NOD() const {
    int numerator   = this->numerator;
    int denominator = this->denominator;
    
    while(numerator > 0 && denominator > 0)
        
        if(numerator > denominator)
            numerator %= denominator;
        else
            denominator %= numerator;
    
    return numerator + denominator;
}

void Fraction::changeToIrreducible() {
    int nod = this->NOD();
    this->numerator   /= nod;
    this->denominator /= nod;
}

