#include "Fraction.h"
#include <iostream>

void Fraction::printFraction() {
    std::cout << this->numerator <<
    std::endl << this->denominator;
}

int Fraction::NOD() {
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

