#include "CustomClass.h"

ostream& operator << (ostream& os, const CustomClass& customClass) {
    os << "First  field: " << customClass.getFirstField() << endl;
    os << "Second field: " << customClass.getSecondField();

    return os;
}