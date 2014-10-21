#pragma onec

#include <iostream>

using namespace std;

class CustomClass {
    float firstField;
    float secondField;

public:

#pragma mark - Constructors -

    CustomClass() : firstField(0), secondField(0) {}

    CustomClass(const float& fistVar, const float& secondVar) : firstField(fistVar),
                                                  secondField(secondVar) {}

#pragma mark - GetMethods -

    float getFirstField() const {
        return this->firstField;
    }

    float getSecondField() const {
        return this->secondField;
    }

#pragma mark - SetMethods -

    void setFirstField(const float& firstField) {
        this->firstField = firstField;
    }

    void setSecondField(const float& secondField) {
        this->secondField = secondField;
    }
};

ostream& operator << (ostream& os, const CustomClass& customClass);