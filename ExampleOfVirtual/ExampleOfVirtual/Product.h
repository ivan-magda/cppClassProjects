#pragma onec

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Product
{
protected:
    int id;
    string maker;
    string model;

public:

    Product(int id_, const string& maker_, const string& model_) :
    id(id_), maker(maker_), model(model_)
    {
        //cout << "Product constructor" << endl;
    }

    virtual ~Product()
    {
        //cout << "Product destructor" << endl;
    }

    string getMaker() const              { return maker; }
    void   setMaker(const string& maker) { this->maker = maker; }

    string getModel() const              { return model; }
    void   setModel(const string& model) { this->model = model; }

    virtual string getInfo() const {
        ostringstream oss;

        oss << "Id: " << id << endl;
        oss << "Maker: " << maker << endl;
        oss << "Model: " << model << endl;

        return oss.str();
        }
};


class Computer : public Product {
    protected:
        int   hdd;
        float cpu;

    public:
        Computer(int id_, const string& maker_, const string& model_,
                 int hdd_, float cpu_) :
        Product(id_, maker_, model_), hdd(hdd_), cpu(cpu_)
            {
                //	cout << "Computer constructor" << endl;
            }

        ~Computer()
            {
                //		cout << "Computer destructor" << endl;
            }

        int  getHdd() const        { return hdd; }
        void setHdd(const int hdd) { this->hdd = hdd; }

        float getCpu() const          { return cpu; }
        void  setCpu(const float cpu) { this->cpu = cpu; }

        string getInfo() const {
            ostringstream oss;

            oss << Product::getInfo();
            
            oss << "HDD: " << hdd << endl;
            oss << "CPU: " << cpu << endl;
            return oss.str();
            }
};


class Printer : public Product {
    public:
    enum Type {MATRIX, INKJET, LASER, SUBLIM};

    protected:

    bool color;
    Type type;
    string resolution;
    char* comment;

    public:
    Printer(int id_, const char* maker_, const char* model_,
            bool color_, Type type_, const char* resolution_,
            const char* comment_ = NULL) : Product(id_, maker_, model_), color(color_), type(type_), resolution(resolution_)
    {
        if (comment_ == NULL) {
            comment = NULL;
        } else {
            size_t len = strlen(comment_);
            comment = new char[len+1];
            strcpy(comment, comment_);
        }
    }

    ~Printer() {
            //		cout << "Printer destructor" << endl;
        delete[] comment;
    }

    string getInfo() const {
        ostringstream oss;
        oss << Product::getInfo();
        oss << "color: " << (color ? "yes" : "no") << endl;
        oss << "type: ";
        switch (type)
            {
                case MATRIX: oss << "matrix"; break;
                case INKJET: oss << "inkjet"; break;
                case LASER:  oss << "laser";  break;
                case SUBLIM: oss << "sublimation"; break;
            }
        oss << endl;
        oss << "resolution: " << resolution << endl;
        return oss.str();
        }
};