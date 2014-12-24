//
//  VectorWithOperations.h
//  Vector
//
//  Created by Ivan Magda on 30.11.14.
//  Copyright (c) 2014 Ivan Magda. All rights reserved.
//

#ifndef __Vector__VectorWithOperations__
#define __Vector__VectorWithOperations__

#include <stdio.h>

#include "Vector.h"

class VectorWithOperations : public Vector {


public:
    VectorWithOperations() : Vector() {}

    VectorWithOperations(float beginX, float beginY, float endX, float endY)
                           : Vector(beginX, beginY, endX, endY) {}

    void multiplicationOnConst(float constanta) {
        setBeginX(getBeginX() * constanta);
        setBeginY(getBeginY() * constanta);
        setEndX(getEndX() * constanta);
        setEndY(getEndY() * constanta);
    }

    VectorWithOperations addition(VectorWithOperations vector) {
        float _beginX = getBeginX() + vector.getBeginX();
        float _beginY = getBeginY() + vector.getBeginY();
        float _endX = getEndX() + vector.getEndX();
        float _endY = getEndY() + vector.getEndY();

        VectorWithOperations result = VectorWithOperations(_beginX, _beginY, _endX, _endY);

        return result;
    }
};

#endif /* defined(__Vector__VectorWithOperations__) */