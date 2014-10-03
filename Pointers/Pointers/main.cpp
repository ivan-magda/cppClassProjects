#include <iostream>
#include <ctime>
#include <iomanip>

#define LIMIT_OF_RANDOM_NUMBER (1000)
#define CREATE_RANDOM_NUMBER(limit) {rand() % limit + 1}

#define ROWS    (7)
#define COLLOMS (6)
#define PLACEHOLDER_FOR_NUMBERS_SETW (3)

using namespace std;

#pragma mark - Function Prototypes -

void fillArrayWithRandomNumbers(int *array, const int& size);

void printElementsOfArrayWithSize(const int *array, const int& size);

int findIndexNumberOfMaxElementInArray(const int *array, const int& size);

int countPositiveElemetsThatIndexGreaterThanIndexOfMaxElementAndFoldToNumber(const int *array, const int& size, int foldNumber);

#pragma mark - Main -

int main(int argc, const char * argv[]) {
    int **array = new int*[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        array[i] = new int[COLLOMS];
        
        fillArrayWithRandomNumbers(array[i], COLLOMS);
        printElementsOfArrayWithSize(array[i], COLLOMS);
        cout << "   result : "
             << countPositiveElemetsThatIndexGreaterThanIndexOfMaxElementAndFoldToNumber(array[i], COLLOMS, 3)
             << endl;
    }
    
    for (int i = 0; i < ROWS; ++i)
        delete array[i];
    delete [] array;
    
    return 0;
}

#pragma mark - Implementation of Functions -

void fillArrayWithRandomNumbers(int *array, const int& size) {
    srand((unsigned)time(NULL));
    
    static int emptyNumbers[ROWS * COLLOMS];
    
    for (int i = 0; i < size; ++i) {
        int randomNumber = CREATE_RANDOM_NUMBER(LIMIT_OF_RANDOM_NUMBER);
        for (int check = 0; check < ROWS * COLLOMS; ++check) {
            if (randomNumber == emptyNumbers[check]) {
                randomNumber = CREATE_RANDOM_NUMBER(LIMIT_OF_RANDOM_NUMBER);
            }
        }
        array[i] = randomNumber;
        
        int indexOfZero;
        for (indexOfZero = 0; emptyNumbers[indexOfZero] != 0; ++indexOfZero) {
        }
        emptyNumbers[indexOfZero] = randomNumber;
    }
}

void printElementsOfArrayWithSize(const int *array, const int& size) {
    for (int i = 0; i < size; ++i)
        cout << setw(PLACEHOLDER_FOR_NUMBERS_SETW) << array[i] << " ";
}

int findIndexNumberOfMaxElementInArray(const int *array, const int& size) {
    int index = 0;
    int maxElement = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > maxElement) {
            maxElement  = array[i];
            index = i;
        }
    }
    return index;
}

int countPositiveElemetsThatIndexGreaterThanIndexOfMaxElementAndFoldToNumber(const int *array, const int& size, int foldNumber)
{
    int count = 0;
    int indexOfMaxElement = findIndexNumberOfMaxElementInArray(array, size);
    for (int i = (indexOfMaxElement != size) ? indexOfMaxElement + 1 : size; i < size; ++i) {
        if ((array[i] > 0) && (i % foldNumber == 0)) {
            ++count;
        }
    }
    return count;
}
