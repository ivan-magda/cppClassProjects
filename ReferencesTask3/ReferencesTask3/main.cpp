#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

float getAmountOfAllElements(float *array, const int size, float& amountOfNegativeNubers) {
    float positiveNumbersAmount = 0;
    float negativeNumbresAmount = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            positiveNumbersAmount += array[i];
        } else if (array[i] < 0) {
            negativeNumbresAmount += array[i];
        }
    }
    amountOfNegativeNubers = negativeNumbresAmount;

    return positiveNumbersAmount;
}

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));

    float firstArray[12];
    float secondArray[10];

    for (int i = 0; i < 12; ++i) {
        firstArray[i] = (rand() % 1000 - 500) * 0.5;
    }

    for (int i = 0; i < 10; i++) {
        secondArray[i] = (rand() % 1000 - 500) * 0.5;
    }

    cout << "First array: ";
    for (int i = 0; i < 12; ++i) {
        cout << firstArray[i] << " ";
    }
    cout << endl;

    cout << "Second array: ";
    for (int i = 0; i < 10; ++i) {
        cout << secondArray[i] << " ";
    }
    cout << endl;


    float firstArrayPositive = 0;
    float firstArrayNegative = 0;

    firstArrayPositive = getAmountOfAllElements(firstArray, 12, firstArrayNegative);
    cout << endl << "First array : positive = " <<  firstArrayPositive << "; negative = " << firstArrayNegative << endl;


    float secondArrayPositive = 0;
    float secondArrayNegative = 0;

    firstArrayPositive = getAmountOfAllElements(secondArray, 10, secondArrayNegative);
    cout        << "First array : positive = " <<  secondArrayPositive << "; negative = " << secondArrayNegative << endl;

    float result = (firstArrayPositive * secondArrayNegative) / (secondArrayPositive + firstArrayNegative);

    cout << endl << "Result = " << result << endl;

    return 0;
}