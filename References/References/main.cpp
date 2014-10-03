#include <iostream>

using namespace std;

#pragma mark - Typedefs -

typedef unsigned short kilogram;
typedef float    gram;

 struct weight {
    kilogram kilogram;
    gram     gram;
};


#pragma mark - Functions Prototypes -

weight changeCurrentWeight(const kilogram& currentKilogram, const gram& currentGram, const float& valueChanges);



#pragma mark - Main -

int main(int argc, const char * argv[]) {
    kilogram kilo;
    gram     gram;
    float    changeValue;
    
    cout << "Enter kilogram: ";
    cin  >> kilo;
    cout << endl;
    
    cout << "Enter gram: ";
    cin  >> gram;
    cout << endl;
    
    cout << "Enter change value: ";
    cin  >> changeValue;
    cout << endl;
    
    weight weight = changeCurrentWeight(kilo, gram, changeValue);
    
    cout << "The result is " << weight.kilogram << " kilogram "
                             << weight.gram     << " gram" << endl;

    return 0;
}


#pragma mark - Function Implementations -

weight changeCurrentWeight(const kilogram& currentKilogram, const gram& currentGram, const float& valueChanges) {
    if (currentKilogram < 0 || currentGram < 0) {
        cerr << "Incorrect input data. Kilogram and gram can not be negative.\n";
        weight badWeight = {0, 0};
        return badWeight;
    }
    
    weight newWeight = {currentKilogram, currentGram};
    newWeight.gram += valueChanges;
    
    if (newWeight.gram >= 1000) {
        int numberOfKilo;
        for (numberOfKilo = 0; newWeight.gram > 1000; newWeight.gram -= 1000) {
            ++numberOfKilo;
        }
        if (numberOfKilo > 0) {
            newWeight.kilogram += numberOfKilo;
        }
    } else {
        while (newWeight.gram < 0) {
            if (newWeight.kilogram == 0) {
                newWeight.gram = 0;
                cerr << "A very big value changes. Weight can not be negative.\n";
                break;
            }
            newWeight.kilogram -= 1;
            newWeight.gram     += 1000;
        }
    }
    return newWeight;
}
