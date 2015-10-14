//
//  main.cpp
//  ComplexNumbersTemplate
//
//  Created by Ivan Magda on 26.05.15.
//  Copyright (c) 2015 Ivan Magda. All rights reserved.
//

#include <iostream>

using namespace std;

template <class T>
class ComplexNumber {
    T realPart;
    T imaginaryPart;

public:

    ComplexNumber () : realPart(0), imaginaryPart(0){}

    ComplexNumber(const T real_part, const T imaginary_part) {
        setRealPart(real_part);
        setImaginaryPart(imaginary_part);
    }

    void setRealPart(const T real_part) {
        this->realPart = real_part;
    }
    void setImaginaryPart(const T imaginary_part) {
        this->imaginaryPart = imaginary_part;
    }

    T getRealPart()      const {return this->realPart;}
    T getImaginaryPart() const {return this->imaginaryPart;}


    bool operator == (const ComplexNumber& number2) const {
        if (this->getRealPart() == number2.getRealPart() &&
            this->getImaginaryPart() == number2.getImaginaryPart())
            return true;
        else
            return false;
    }

    bool operator != (const ComplexNumber& number2) const {
        return !(*this == number2);
    }

    ComplexNumber& operator = (const ComplexNumber number2) {
        this->SetRealPart(number2.getRealPart());
        this->SetImaginaryPart(number2.getImaginaryPart());

        return *this;
    }

    ComplexNumber operator + (const ComplexNumber& number2) const {
        ComplexNumber result;

        T real_part = (this->getRealPart() + number2.getRealPart());
        T imaginary_part = (this->getImaginaryPart() + number2.getImaginaryPart());

        result.setRealPart(real_part);
        result.setImaginaryPart(imaginary_part);
        
        return result;
    }

    ComplexNumber operator - (const ComplexNumber& number2) const {
        ComplexNumber result;

        T real_part = (this->getRealPart() - number2.getRealPart());
        T imaginary_part = (this->getImaginaryPart() - number2.getImaginaryPart());

        result.setRealPart(real_part);
        result.setImaginaryPart(imaginary_part);
        
        return result;
    }

    ComplexNumber operator * (const ComplexNumber& number2) const {
        ComplexNumber result;

        T real_part;
        T imaginary_part;

        real_part = (this->getRealPart()      * number2.getRealPart() -
                     this->getImaginaryPart() * number2.getImaginaryPart());

        imaginary_part = (this->getRealPart() * number2.getImaginaryPart() +
                          this->getImaginaryPart() * number2.getRealPart());

        result.setRealPart(real_part);
        result.setImaginaryPart(imaginary_part);
        
        return result;
    }

    ComplexNumber operator / (const ComplexNumber& number2) const {
        ComplexNumber result;

        T denominator, real_part, imaginary_part;

        denominator = (number2.getRealPart() * number2.getRealPart() +
                       number2.getImaginaryPart() * number2.getImaginaryPart());

        real_part = ((this->getRealPart() * number2.getRealPart() +
                      this->getImaginaryPart() * number2.getImaginaryPart()) / denominator);

        imaginary_part = ((number2.getRealPart() * this->getImaginaryPart() -
                           this->getRealPart() * number2.getImaginaryPart()) / denominator);

        result.setRealPart(real_part);
        result.setImaginaryPart(imaginary_part);
        
        return result;
    }

    friend ostream& operator<< (ostream& os, const ComplexNumber& number) {
        os << number.getRealPart();

        if (number.getImaginaryPart() > 0) {
            os << '+';
        }
        os << number.getImaginaryPart() << 'i';
        
        return os;
    }
};

int main(int argc, const char * argv[]) {
    ComplexNumber<float> test1(-2.2, 5.3);
    ComplexNumber<float> test2(3.2, -4.5);
    ComplexNumber<float> test3(13.1, 1.1);
    ComplexNumber<float> test4(7.2, -6.4);

    cout << ((test1 == test2) ? "true" : "false") << endl;
    cout << ((test1 != test2) ? "true" : "false") << endl;
    cout << test1 + test2 << endl;
    cout << test2 - test1 << endl;
    cout << test1 * test2 << endl;
    cout << test3 / test4 << endl << endl;

    return 0;
}
