#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

float countAverage(int *array, int size);

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));

    int matrix[4][6];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            int randomNumber = rand() % 1000 - 500;
            matrix[i][j] = randomNumber;
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        if (i % 2 != 0) {
            cout << i + 1 << ")Average = " << setw(10) << countAverage(matrix[i], 6) << endl;
        }
    }


    return 0;
}

float countAverage(int *array, const int size) {
    float averageAmount = 0;
    float averageCount  = 0;
    for (int i = 0; i < size; ++i) {
        if (i % 2 != 0) {
            averageAmount += array[i];
            ++averageCount;
        }
    }
    return averageAmount / averageCount;
}