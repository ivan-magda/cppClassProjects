//
//  main.cpp
//  Vector
//
//  Created by Ivan Magda on 30.11.14.
//  Copyright (c) 2014 Ivan Magda. All rights reserved.
//

#include "VectorWithOperations.h"

int main() {
    Vector vector = Vector(2, 4, 4, 8);
    vector.printInfo();
    cout << "\nLength = " << vector.length() << endl;
    
    vector.paintMe();
    cout << endl << endl;

    VectorWithOperations vectorOperations = VectorWithOperations(2, 4, 4, 8);
    vectorOperations.multiplicationOnConst(3);
    vectorOperations.printInfo();
    cout << "\nLength = " << vectorOperations.length() << endl;

    vectorOperations.paintMe();
    cout << endl << endl;

   VectorWithOperations addition = vectorOperations.addition(VectorWithOperations(1, 4, 6, 6));
    addition.printInfo();
    cout << "\nLength = " << addition.length() << endl;

    addition.paintMe();
    cout << endl;
}