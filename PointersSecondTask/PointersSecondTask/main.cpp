#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void printMatrix(int *array, int size);

float countArithmeticalMeanNumbers(int *array, int size);

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));

    int matrix[4][8];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            int randomNumber = rand() % 1000 - 500;
            *(*(matrix + i)+j) = randomNumber;
        }
    }

    for (int i = 0; i < 4; ++i) {
        printMatrix(*(matrix + i), 8);
    }

    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << ") "
             << "Среднее арифметическое отрицательных элементов = "
             << countArithmeticalMeanNumbers(*(matrix + i), 8) << endl;
    }

    return 0;
}

void printMatrix(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << setw(5) << *(array + i) << " ";
    }
    cout << endl;
}

float countArithmeticalMeanNumbers(int *array, int size) {
    int countLowThenZero = 0;
    int countOfNumbers   = 0;
    for (int i = 0; i < size; ++i) {
        if (*(array + i) < 0) {
            countLowThenZero += *(array + i);
            ++countOfNumbers;
        }
    }
    return ((float)countLowThenZero / countOfNumbers);
}