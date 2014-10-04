#include "FractionOperations.h"

FractionOperations FractionOperations::operator *(const FractionOperations& secondFraction) const {
    int newNumerator   = this->getNumerator()   * secondFraction.getNumerator();
    int newDenominator = this->getDenominator() * secondFraction.getDenominator();

    FractionOperations resultOfMultiplication(newNumerator, newDenominator);

    return resultOfMultiplication;
}

FractionOperations FractionOperations::operator / (const FractionOperations& secondFraction) const {
    int newNumerator   = this->getNumerator()   * secondFraction.getDenominator();
    int newDenominator = this->getDenominator() * secondFraction.getNumerator();

    FractionOperations resultOfDivision(newNumerator, newDenominator);

    return resultOfDivision;
}