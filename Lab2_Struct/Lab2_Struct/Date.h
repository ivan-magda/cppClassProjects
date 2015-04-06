#pragma onec

#include <fstream>

using namespace std;

class Date
{
public:
     enum Month {
                    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG,
                    SEP, OCT, NOV, DEC, MONTHS = 12
                };
private:
	int dd;
	Month mm;
	int yyyy;
    
public:
    Date() : dd(1), mm(JAN), yyyy(1970)
    {}
    
    Date(int d, Month m, int y) : dd(d), mm(m), yyyy(y)
    {}
    
    int getYear()  const {return this->yyyy;}
    int getDay()   const {return this->dd;}
    int getMonth() const {return this->mm;}
    
    void setYear(int year)     {this->yyyy = year;}
    void setDay(int day)       {this->dd = day;}
    void setMonth(Month month) {this->mm = month;}
    
    int daysInMonth() const;
    
    bool isLeapYear() const;
    
    bool operator < (const Date& date2) const;
    bool operator > (const Date& date2) const;
    
    Date& operator ++ ();
    Date  operator ++ (int);
    
    Date& operator -- ();
    Date  operator -- (int);
    
    bool operator == (const Date& date2) const;
    bool operator != (const Date& date2) const;
    
    int operator - (Date& date2);

    static Date getCurrentDate();
    
private:
    int GetNumDaysInMonth() const;
    int GetNumDaysInYear () const;
};

ostream& operator << (ostream& os, const Date& date);
istream& operator >> (istream& is, Date& date);

const bool isLeapYear(int date);
