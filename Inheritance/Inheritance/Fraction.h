#pragma onec

#include <stdio.h>


class Fraction {

private:
    
    int numerator;
    int denominator;

#pragma mark - Constructors -
    
public:
    
    Fraction() {
        this->numerator   = 0;
        this->denominator = 0;
    }

    Fraction(const int& _numerator, const int& _denominator) : numerator(_numerator), denominator(_denominator) {}
    
#pragma mark - Public Methdos define -

    int getNumerator() const {
        return this->numerator;
    }

    int getDenominator() const {
        return this->denominator;
    }

    void setNumerator(const int& _numerator) {
        this->numerator = _numerator;
    }

    void setDenominator(const int& _denominator) {
        this->denominator = _denominator;
    }

    void printFraction() const;
    
    void changeToIrreducible();

#pragma mark - Private Methods define -
    
private:
    
    int NOD() const;
};