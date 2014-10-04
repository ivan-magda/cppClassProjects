#pragma onec

#include <stdio.h>
#include "Fraction.h"

class FractionOperations : public Fraction {

#pragma mark - Constructors define -

public:

    FractionOperations():Fraction() {}

    FractionOperations(const int& _numerator, const int& _denominator):Fraction(_numerator, _denominator) {}

    #pragma mark - Public methods define -

    FractionOperations operator * (const FractionOperations& secondFraction) const;

    FractionOperations operator / (const FractionOperations& secondFraction) const;
};