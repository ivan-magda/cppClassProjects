//
//  Vector.h
//  Vector
//
//  Created by Ivan Magda on 30.11.14.
//  Copyright (c) 2014 Ivan Magda. All rights reserved.
//

#ifndef __Vector__Vector__
#define __Vector__Vector__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

class Vector {
private:
    float beginX;
    float beginY;
    float endX;
    float endY;
public:
    Vector() : beginX(0), beginY(0), endX(0), endY(0) {}

    Vector(float beginX, float beginY, float endX, float endY) {
        this->beginX = beginX;
        this->beginY = beginY;
        this->endX = endX;
        this->endY = endY;
    }

    void printInfo() {
        cout << "X: " << beginX << "," << beginY << "; ";
        cout << "Y: " << endX << "," << endY << ";";
    }

    float length() {
        float X = this->getX();
        float Y = this->getY();

        float length = sqrt(X*X + Y*Y);

        return length;
    }

    void paintMe() {
        int length = abs(this->length());
        float X = this->getX();
        float Y = this->getY();

        cout << X;
        for (int i = 0; i < length; ++i) {
            cout << "-";
        }
        cout << ">" << Y;
    }

    void setBeginX(float x) {
        this->beginX = x;
    }

    void setBeginY(float y) {
        this->beginY = y;
    }

    void setEndX(float x) {
        this->endX = x;
    }

    void setEndY(float y) {
        this->endY = y;
    }

    float getBeginX() {
        return beginX;
    }

    float getBeginY() {
        return beginY;
    }

    float getEndX() {
        return endX;
    }

    float getEndY() {
        return endY;
    }

protected:
    float getX() {
        return endX - beginX;
    }

    float getY() {
        return endY - beginY;
    }
};

#endif /* defined(__Vector__Vector__) */