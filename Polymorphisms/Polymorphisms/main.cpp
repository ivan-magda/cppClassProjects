#include <iostream>
#include "InheritorCustomClass.h"

int main(int argc, const char * argv[]) {

    CustomClass customClass(2.8, 3.9);
    cout << customClass << endl;

        //assign operator
    InheritorCustomClass inheritorCustomClass(3.5, 59.1);
    InheritorCustomClass classtoCopy(2.2, 4.4);

    inheritorCustomClass = classtoCopy;
    cout << "\nassign operator\n"
         << inheritorCustomClass << endl;


        //composite subtraction operator
    InheritorCustomClass inheritorSubOperator(5.1, 12.5);
    inheritorSubOperator -= InheritorCustomClass(2.4, 7.9);
    cout << "\ncomposite subtraction operator\n"
         << inheritorSubOperator << endl;


        //integral division operator
    InheritorCustomClass inheritorDivisOperator(5.0, 18.0);
    inheritorDivisOperator /= InheritorCustomClass(4.0, 5.0);
    cout << "\nintegral division operator\n"
         << inheritorDivisOperator << endl << endl;


    return 0;
}