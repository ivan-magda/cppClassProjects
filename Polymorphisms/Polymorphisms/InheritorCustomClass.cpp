#include "InheritorCustomClass.h"

InheritorCustomClass& InheritorCustomClass::operator = (const InheritorCustomClass& classToCopy) {
    this->setFirstField(classToCopy.getFirstField());
    this->setSecondField(classToCopy.getSecondField());

    return *this;
}

InheritorCustomClass& InheritorCustomClass::operator -= (const InheritorCustomClass& secondClass) {
    float newFirstField  = this->getFirstField()  - secondClass.getFirstField();
    float newSecondField = this->getSecondField() - secondClass.getSecondField();

    this->setFirstField(newFirstField);
    this->setSecondField(newSecondField);

    return *this;
}

InheritorCustomClass& InheritorCustomClass::operator /= (const InheritorCustomClass& secondClass) {
    float newFirstField  = this->getFirstField()  / secondClass.getFirstField();
    float newSecondField = this->getSecondField() / secondClass.getSecondField();

    this->setFirstField(newFirstField);
    this->setSecondField(newSecondField);

    return *this;
}