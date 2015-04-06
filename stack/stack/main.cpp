//
//  main.cpp
//  stack
//
//  Created by Ivan Magda on 03.03.15.
//  Copyright (c) 2015 Ivan Magda. All rights reserved.
//

#include <iostream>
#include <stack>
#include <time.h>
#include <math.h>

static const int kRandValue = 100;
static const int kNumber = 10;

using namespace std;

void printStack(stack<int> stack);

int minValue(stack<int> stack, int& index);
int maxValue(stack<int> stack, int& index);

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));

    stack<int> myStack;

    for (int i = 0; i < kNumber; ++i) {
        int value = (rand() % kRandValue - kRandValue/2);
        myStack.push(value);
    }

    printStack(myStack);
    cout << endl;

    int minimumValueIndex = 0;
    int maximumValueIndex = 0;
    int minimumValue = minValue(myStack, minimumValueIndex);
    int maximumValue = maxValue(myStack, maximumValueIndex);

    cout << "Max value = " << maximumValue << " index: " << maximumValueIndex
         << " Min value = " << minimumValue << " index:  " << minimumValueIndex << endl;

        //set start and end indexes
    int startIndex;
    int endIndex;
    if (maximumValueIndex > minimumValueIndex) {
        startIndex = minimumValueIndex;
        endIndex = maximumValueIndex;
    } else {
        startIndex = maximumValueIndex;
        endIndex = minimumValueIndex;
    }
    cout << "Start index " << startIndex << endl
         << "End index "   << endIndex   << endl;


        //Calculate geometric mean
    long long negativeValuesMultiplication = 1;
    int countNegative = 0;
    for (int i = (int)myStack.size() - 1; !myStack.empty(); --i) {
        if (i > startIndex && i < endIndex) {
            if (myStack.top() < 0) {
                negativeValuesMultiplication *= myStack.top();
                ++countNegative;
            }
        }
        myStack.pop();
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

void printStack(stack<int> stack) {
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}

int minValue(stack<int> stack, int& index) {
    int minValue = 0;
    int i = (int)stack.size() - 1;
    while (!stack.empty()) {
        int currentValue = stack.top();
        if (currentValue < minValue) {
            minValue = currentValue;
            index = i;
        }
        stack.pop();
        --i;
    }
    return minValue;
}

int maxValue(stack<int> stack, int& index) {
    int maxValue = 0;
    int i = (int)stack.size() - 1;
    while (!stack.empty()) {
        int currentValue = stack.top();
        if (currentValue > maxValue) {
            maxValue = currentValue;
            index = i;
        }
        stack.pop();
        --i;
    }
    return maxValue;
}
