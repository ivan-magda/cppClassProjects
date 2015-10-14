#include "Date.h"
#include <iostream>
#include <ctime>
#include <iomanip>

ostream& operator << (ostream& os, const Date& date)
{
	os << setfill('0');
	os << setw(2) << date.getDay() << '.';
	os << setw(2) << (int)date.getMonth() << '.';
	os << setw(4) << date.getYear();
	os << setfill(' ');
	return os;
}

istream& operator >> (istream& is, Date& date)
{
    char character;
    int dd, mm ,yyyy;
    
    is  >> dd >> character
        >> mm >> character
        >> yyyy;
    
    date.setDay(dd);
    date.setMonth((Date::Month)mm);
    date.setYear(yyyy);
    
    return is;
}

bool Date::operator == (const Date& date2) const
{
    return (this->yyyy == date2.yyyy &&
            this->mm == date2.mm     &&
            this->dd == date2.dd);
}

bool Date::operator != (const Date& date2) const
{
    return !(*this == date2);
}

bool Date::isLeapYear() const
{
    if (yyyy % 4 == 0 &&
       (yyyy % 100 != 0 || yyyy % 400 == 0))
        return true;
    else
        return false;
}

const bool isLeapYear(int date)
{
    if (date % 4 == 0 &&
       (date % 100 != 0 || date % 400 == 0))
        return true;
    else
        return false;
}

Date Date::getCurrentDate()
{
    Date currentDate;
    
    time_t timestamp;
    tm* ptm;
    
    time(&timestamp);
    
    ptm = gmtime(&timestamp);
    
    currentDate.dd = ptm->tm_mday;
    currentDate.mm = (Month)(ptm->tm_mon + 1);
    currentDate.yyyy = ptm->tm_year + 1900;
    
    return currentDate;
}

int Date::daysInMonth() const
{
    int num_days = 0;
    
    if (mm == JAN) num_days = 31;
    else if (mm == FEB) num_days = 28 + this->isLeapYear();
    else if (mm == MAR) num_days = 31;
    else if (mm == APR) num_days = 30;
    else if (mm == MAY) num_days = 31;
    else if (mm == JUN) num_days = 30;
    else if (mm == JUL) num_days = 31;
    else if (mm == AUG) num_days = 31;
    else if (mm == SEP) num_days = 30;
    else if (mm == OCT) num_days = 31;
    else if (mm == NOV) num_days = 30;
    else if (mm == DEC) num_days = 31;
    
    return num_days;
}

int Date::GetNumDaysInMonth() const
{
    const int DaysInMonth[12] = {31, 28, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31};
    int num_days = 0;
    int num_month = this->getMonth()-1;
    
    for (int month = 0; month < num_month; ++month)
        num_days += DaysInMonth[month];
    
    return num_days;
}

int Date::GetNumDaysInYear() const
{
    int num_days = 0;
    int num_years = this->getYear();
    
    for (int year = 0; year < num_years; ++year)
        num_days += 365 + (::isLeapYear(year));
    
    return num_days;
}

int Date::operator - (Date& date2)
{
    int num_days_date1 = this->dd;
    int num_days_date2 = date2.dd;
    
    num_days_date1 += this->GetNumDaysInMonth();
    num_days_date2 += date2.GetNumDaysInMonth();
    
    num_days_date1 += this->GetNumDaysInYear();
    num_days_date2 += date2.GetNumDaysInYear();
    
    return  num_days_date1 - num_days_date2;
}

Date& Date::operator ++ ()
{
    if (dd < daysInMonth())
        dd++;
    else
    {
        dd = 1;
        if (mm == DEC)
        {
            mm = JAN;
            yyyy++;
        }
        else
        {
            int month = mm;
            month++;
            mm = static_cast<Month>(month);
        }
    }
    return *this;
}

Date Date::operator ++ (int)
{
    Date oldDate(*this);
    ++(*this);
    return oldDate;
}

Date& Date::operator -- ()
{
    if((dd == 1) && (mm != JAN))
    {
        int mm = this->mm - 1;
        this->mm = static_cast<Month>(mm);
        this->dd = this->daysInMonth();
    }
    else if(mm == JAN && dd == 1)
    {
        yyyy--;
        mm = DEC;
        dd = 31;
    }
    else
        dd--;
    
    return *this;
}

Date Date::operator -- (int)
{
    Date oldDate = *this;
    --(*this);
    return oldDate;
}

bool Date::operator < (const Date& date2) const
{
    return (this->yyyy < date2.yyyy) ||
    (this->yyyy == date2.yyyy && this->mm <  date2.mm) ||
    (this->yyyy == date2.yyyy && this->mm == date2.mm && this->dd < date2.dd);
}

bool Date::operator > (const Date& date2) const
{
    return !(*this < date2);
}
