#include <iostream>
#include "CustomClass.h"

#pragma onec

class InheritorCustomClass : public CustomClass {

public:

#pragma mark - Constructors -

    InheritorCustomClass() : CustomClass() {}

    InheritorCustomClass(const float& firstField, const float& secondField) : CustomClass(firstField, secondField) {}

#pragma mark - Operators -

    InheritorCustomClass& operator = (const InheritorCustomClass& classToCopy);

    InheritorCustomClass& operator -= (const InheritorCustomClass& secondClass);

    InheritorCustomClass& operator /= (const InheritorCustomClass& secondClass);
};