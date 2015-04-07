//
//  main.cpp
//  Lab2_Struct
//
//  Created by Ivan Magda on 06.04.15.
//  Copyright (c) 2015 Ivan Magda. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Date.h"

static const int WIDTH = 10;
static const int NUMBER_FLIGHTS = 10;

using namespace std;

struct Time {
    int hh;
    int mm;
};

struct Flight {
    string destination;
    string flightNumber;
    Date date;
    Time timeDeparture;
    Time flightTime;
    float ticketPrice;
    bool isTicketsAvaliable;
};

Time time(int hh, int mm) {
    Time time;
    time.hh = hh;
    time.mm = mm;
    return time;
}

void CreateFlight(Flight& flight, string destination, string flightNumber, Date date, Time timeDeparture, Time flightTime, float ticketPrice, bool isTicketsAvaliable);

void SearchFlightByDestinationAndPrint(const Flight *flights, const string destination, const int size);

bool sortByTimeDeparture(Flight flight1, Flight flight2) {
    return (flight1.timeDeparture.hh < flight2.timeDeparture.hh && flight1.timeDeparture.mm < flight2.timeDeparture.mm);
}

bool sortByDestination(Flight flight1, Flight flight2) {
    return (flight1.destination < flight2.destination);
}

void PrintAllFlights(const Flight *flights, const int size);

ostream& operator << (ostream& os, const Flight& flight);

int main(int argc, const char * argv[]) {
    Flight flights[NUMBER_FLIGHTS];

    CreateFlight(flights[0], "Москва", "UN-196", Date(6, Date::Month::APR, 2015), time(10, 30), time(8, 0), 10000, true);
    CreateFlight(flights[1], "Москва", "ПЛ-6578", Date(6, Date::Month::APR, 2015), time(15, 35), time(8, 0), 7500, true);
    CreateFlight(flights[2], "Пхукет", "KAR-2705", Date(6, Date::Month::APR, 2015), time(13, 10), time(10, 0), 15000, true);
    CreateFlight(flights[3], "Якутск", "ЯК-597", Date(7, Date::Month::APR, 2015), time(9, 20), time(2, 15), 3500, true);
    CreateFlight(flights[4], "Москва", "UN-196", Date(7, Date::Month::APR, 2015), time(10, 30), time(8, 00), 9500, true);
    CreateFlight(flights[5], "Москва", "ПЛ-6578", Date(7, Date::Month::APR, 2015), time(13, 45), time(8, 0), 7500, false);
    CreateFlight(flights[6], "Красноярск", "ЭК", Date(7, Date::Month::APR, 2015), time(7, 20), time(5, 20), 5000, true);
    CreateFlight(flights[7], "Хабаровск", "ЯК-598", Date(7, Date::Month::APR, 2015), time(14, 30), time(2, 00), 5000, true);
    CreateFlight(flights[8], "Владивосток", "ЭК-511", Date(7, Date::Month::APR, 2015), time(14, 50), time(3, 0), 6500, true);
    CreateFlight(flights[9], "Бангкок", "KAR-9801", Date(7, Date::Month::APR, 2015), time(19, 00), time(10, 00), 15050, false);

    int item = 0;
    do {
        cout << "1. Вывести доступные рейсы до введенного пункта назначения.\n"
             << "2. Вывести все доступные рейсы.\n"
             << "3. Выход\n";

        cin >> item;
        switch (item) {
            case 1: {
                cout << "Введите пункт назначения:";
                string destination;
                cin >> destination;
                SearchFlightByDestinationAndPrint(flights, destination, NUMBER_FLIGHTS);
                break;
            }
            case 2: {
                cout << "Все рейсы:" << endl;
                PrintAllFlights(flights, NUMBER_FLIGHTS);
                break;
            }
            case 3:
                return 0;
            default:
                continue;
        }
    } while (item != 3);

    return 0;
}

void CreateFlight(Flight& flight, string destination, string flightNumber, Date date, Time timeDeparture, Time flightTime, float ticketPrice, bool isTicketsAvaliable) {
    flight.destination = destination;
    flight.flightNumber = flightNumber;
    flight.date = date;
    flight.timeDeparture = timeDeparture;
    flight.flightTime = flightTime;
    flight.ticketPrice = ticketPrice;
    flight.isTicketsAvaliable = isTicketsAvaliable;
}

ostream& operator << (ostream& os, const Flight& flight) {
    os << setw(WIDTH) << left << "Destination:      "     << setw(WIDTH) << right << flight.destination << endl
       << setw(WIDTH) << left << "Flight number:    "     << setw(WIDTH) << right << flight.flightNumber  << endl
       << setw(WIDTH) << left << "Date:             "                    << right << flight.date << endl

       << setw(WIDTH) << left << "Time Departure:"    << setw(WIDTH) << right
                              << flight.timeDeparture.hh << ":" << flight.timeDeparture.mm << endl
       << setw(WIDTH) << left << "Flight time:   "       << setw(WIDTH) << right
                              << flight.flightTime.hh << ":" << flight.flightTime.mm << endl

       << setw(WIDTH) << left << "Ticket price:     " << setw(WIDTH) << right << flight.ticketPrice << endl
       << setw(WIDTH) << left << "Tickets avaliable:" << setw(WIDTH) << right << (flight.isTicketsAvaliable ? "YES" : "NO") << endl;

    return os;
}

void SearchFlightByDestinationAndPrint(const Flight* flights, const string destination, const int size) {
    vector<Flight> foundFlights;
    foundFlights.reserve(size/2);

    for (int i = 0; i < size; ++i) {
        if(flights[i].destination == destination &&
           flights[i].isTicketsAvaliable) {
            foundFlights.push_back(flights[i]);
        }
    }

    sort(foundFlights.begin(), foundFlights.end(), sortByTimeDeparture);

    for (vector<Flight>::iterator it = foundFlights.begin(); it != foundFlights.end(); ++it) {
        cout << *it << endl;
    }
}

void PrintAllFlights(const Flight *flights, const int size) {
    vector<Flight>fligthsToPrint;
    fligthsToPrint.reserve(size);

    for (int i = 0; i < size; ++i) {
        fligthsToPrint.push_back(flights[i]);
    }

    sort(fligthsToPrint.begin(), fligthsToPrint.end(), sortByDestination);

    for (vector<Flight>::iterator it = fligthsToPrint.begin(); it != fligthsToPrint.end(); ++it) {
        cout << *it << endl;
    }
}
