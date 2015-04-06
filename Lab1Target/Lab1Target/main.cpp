    //
    //  main.cpp
    //  Lab1Target
    //
    //  Created by Ivan Magda on 27.02.15.
    //  Copyright (c) 2015 Ivan Magda. All rights reserved.
    //

#include <iostream>
#include <math.h>

static const int kRadius = 1.0f;
static const int kNumberChecking = 5;

using namespace std;

bool isInCircle(const float& x, const float& y);
bool isTopLine(const float& x, const float& y);
bool isBottomLine(const float& x, const float& y);

int main(int argc, const char * argv[]) {
    cout << "Enter point for checking." << endl;

    float x = 0.0f;
    float y = 0.0f;
    int successCounter = 0;
    int failureCounter = 0;
    for (int i = 0; i < kNumberChecking; ++i) {
        cout << "x: ";
        cin  >> x;
        cout << endl;

        cout << "y: ";
        cin  >> y;
        cout << endl;
        if (isInCircle(x, y) && isTopLine(x, y) && isBottomLine(x, y)) {
            cout << "Point in body." << endl;
            ++successCounter;
            continue;
        } else if (x <= 0) {
            if (isTopLine(x, y) && isBottomLine(x, y)) {
                cout << "Point in body." << endl;
                ++successCounter;
                continue;
            }
        }
        cout << "Point outside body." << endl;
        ++failureCounter;
    }

    cout << "\nPoint in body: " << successCounter << endl
         << "point outside: " << failureCounter << endl;

    return 0;
}

bool isInCircle(const float& x, const float& y) {
    return (powf(x, 2) + powf(y, 2) <= pow(kRadius, 2));
}

bool isTopLine(const float& x, const float& y) {
    return (y <= 0.5f*x + 1);
}

bool isBottomLine(const float& x, const float& y) {
    return (y >= -0.5f*x - 1);
}
