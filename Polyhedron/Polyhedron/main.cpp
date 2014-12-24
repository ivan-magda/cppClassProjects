#include <iostream>
#include <math.h>

using namespace std;

class RegularPolyhedron {
protected:
    int edgeLength;
    int edgeNumber;

public:
    virtual double area()    const = 0;
    virtual double volume()  const;
    virtual void printInfo() const;

    void setEdgeLength(int length) { edgeLength = length; }
    void setEdgeNumber(int number) { edgeNumber = number; }

    int getEdgeLength() const { return edgeLength; }
    int getEdgeNumber() const { return edgeNumber; }
};

class Tetrahedron : public RegularPolyhedron {

public:

    Tetrahedron() : RegularPolyhedron() {
        setEdgeLength(0);
        setEdgeNumber(6);
    }

    Tetrahedron(int length) : RegularPolyhedron() {
        setEdgeLength(length);
        setEdgeNumber(6);
    }

    double area() const {
        return (pow(getEdgeLength(), 2) * sqrt(3));
    }

    double volume() const {
        return (pow(getEdgeLength(), 3) * (sqrt(2) / 12) );
    }

    void printInfo() const {
        cout << "Area = "   << area()   << endl
             << "Volume = " << volume() << endl;
    }
};


int main(int argc, const char * argv[]) {
    Tetrahedron tetrahedron = Tetrahedron(4);
    tetrahedron.printInfo();

    return 0;
}
