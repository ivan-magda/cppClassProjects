//
//  main.cpp
//  Vector
//
//  Created by Ivan Magda on 28.02.15.
//  Copyright (c) 2015 Ivan Magda. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>

static const int kRandValue = 100;
static const int kNumber = 100;

using namespace std;

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));

        //Defines an empty vector, and then tells it to make room for 10 integers.
    vector<int> vector;
    vector.reserve(kNumber);

        //Filling vector with random numbers
    for (int i = 0; i < vector.capacity(); ++i) {
        int value = (rand() % kRandValue - kRandValue/2);
        vector.push_back(value);
    }

        //print elements of vector
    for (int i = 0; i < vector.size(); ++i) {
        cout << vector.at(i) << "\t";
    }
    cout << endl;

        //Find max and min values, also indexes
    int minValue = 0;
    int maxValue = 0;
    int minValueIndex = 0;
    int maxValueIndex = 0;
    for (int i = 0; i < vector.size(); ++i) {
        if (vector.at(i) < minValue) {
            minValue = vector.at(i);
            minValueIndex = i;
        }
        if (vector.at(i) > maxValue) {
            maxValue = vector.at(i);
            maxValueIndex = i;
        }
    }
    cout << "MaxValue = " << maxValue
         << " index: "    << maxValueIndex << endl;
    cout << "MinValue = " << minValue
         << " index: "    << minValueIndex << endl;

        //set start and end indexes
    int startIndex;
    int endIndex;
    if (maxValueIndex > minValueIndex) {
        startIndex = minValueIndex;
        endIndex = maxValueIndex;
    } else {
        startIndex = maxValueIndex;
        endIndex = minValueIndex;
    }
    cout << "\nStartIndex " << startIndex
         << "\nEndindex " << endIndex << endl;

        //Calculate geometric mean
    long long negativeValuesMultiplication = 1;
    int countNegative = 0;
    for (int i = startIndex + 1; i < endIndex; ++i) {
        if (vector.at(i) < 0) {
            negativeValuesMultiplication *= vector.at(i);
            ++countNegative;
        }
    }
    cout << "NegativeValuesMultiplication = " << negativeValuesMultiplication << endl
         << "Count " << countNegative << endl;

    double result = 0;
    for (int i = 0; i < countNegative; ++i) {
        result = sqrtf(abs(negativeValuesMultiplication));
    }
    cout << "Geometric mean = " << result << endl;

    return 0;
}
