#include <iostream>
#include <iomanip>
#include <vector>
#include "Date.h"

using namespace std;

struct Weather {
    Date date;
    float daytimeTemperature; //дневная температура
    float nightTemperature; //ночная температура
    bool precipitation; //осадки
    int atmosphericPressure; //атмосферное давление
    float airHumidity; //влажность воздуха
};

    //создание дня с информацией о погоде
void makeWeather(Weather& weather, Date date, float daytimeTemperature, float nightTemperature, bool precipitation, int atmosphericPressure, float airHumidity) {
    weather.date = date;
    weather.daytimeTemperature = daytimeTemperature;
    weather.nightTemperature = nightTemperature;
    weather.precipitation = precipitation;
    weather.atmosphericPressure = atmosphericPressure;
    weather.airHumidity = airHumidity;
}

    //форматированный вывод погоды
ostream& operator << (ostream& os, const Weather& weather) {
    const int WIDTH = 10;

    os << setw(WIDTH) << left << "Date:                " << setw(WIDTH) << right << weather.date << endl
       << setw(WIDTH) << left << "Night Temperature:   " << setw(WIDTH) << right << weather.nightTemperature << endl
       << setw(WIDTH) << left << "Daytime Temperature: " << setw(WIDTH) << right << weather.daytimeTemperature << endl
       << setw(WIDTH) << left << "Precipitation:       " << setw(WIDTH) << right << (weather.precipitation ? "YES" : "NO") << endl
       << setw(WIDTH) << left << "Atmospheric Pressure:" << setw(WIDTH) << right << weather.atmosphericPressure << endl
       << setw(WIDTH) << left << "Air Humidity:        " << setw(WIDTH) << right << weather.airHumidity << endl;

    return os;
}

    //Вывод самого холодного и теплого дня
void printColdestAndWarmestDays(Weather *weather, const int size) {
    Weather coldestDay;
    Weather warmestDay;

    float coldest =  100;
    float warmest = -100;

    for (int i = 0; i < size; ++i) {
        Weather currentWeather = weather[i];
        if (currentWeather.daytimeTemperature < coldest ||
            currentWeather.nightTemperature   < coldest) {
            coldest = (currentWeather.daytimeTemperature > currentWeather.nightTemperature ? currentWeather.nightTemperature : currentWeather.daytimeTemperature);
            coldestDay = currentWeather;
        }

        if (currentWeather.daytimeTemperature > warmest ||
            currentWeather.nightTemperature   > warmest) {
            warmest = (currentWeather.daytimeTemperature > currentWeather.nightTemperature ? currentWeather.daytimeTemperature : currentWeather.nightTemperature);
            warmestDay = weather[i];
        }
    }

    cout << "Coldest" << endl << coldestDay << endl
         << "Warmest" << endl << warmestDay << endl;
}

    //Вывод средней температуры за месяц
void printAverageTemperatureOfTheMonth(Weather *weather, const int size, Date::Month month) {
    vector<Weather> foundDates;
    foundDates.reserve(size/2);

    for (int i = 0; i < size; ++i) {
        if (weather[i].date.getMonth() == month) {
            foundDates.push_back(weather[i]);
        }
    }

    float sum = 0.0f;
    for (vector<Weather>::iterator it = foundDates.begin(); it != foundDates.end(); ++it) {
        Weather weather = *it;
        sum += weather.daytimeTemperature;
    }

    cout << "Average temperature of the month: " << (sum / foundDates.size()) << endl;
}

    //Подсчет дней с осадками
int countForDatesWithPrecipitation(Weather *weather, const int size, Date::Month month) {
    vector<Weather> foundDates;
    foundDates.reserve(size/2);

    for (int i = 0; i < size; ++i) {
        if (weather[i].date.getMonth() == month &&
            weather[i].precipitation == true) {
            foundDates.push_back(weather[i]);
        }
    }

    return (int)foundDates.size();
}

int main(int argc, const char * argv[]) {
    const int size = 10;

    Weather weather[size];

    makeWeather(weather[0], Date( 2, Date::Month::JUN, 2015), 21,  8, false, 739, 42);
    makeWeather(weather[1], Date( 3, Date::Month::JUN, 2015), 22, 10, false, 741, 35);
    makeWeather(weather[2], Date( 4, Date::Month::JUN, 2015), 26, 13, false, 737, 32);
    makeWeather(weather[3], Date( 5, Date::Month::JUN, 2015), 21, 16, true,  740, 50);
    makeWeather(weather[4], Date( 6, Date::Month::JUN, 2015), 21, 15, false, 744, 41);
    makeWeather(weather[5], Date( 7, Date::Month::JUN, 2015), 21, 13, true,  744, 52);
    makeWeather(weather[6], Date( 8, Date::Month::JUN, 2015), 21, 14, true,  735, 58);
    makeWeather(weather[7], Date( 9, Date::Month::JUN, 2015), 22, 14, true,  738, 58);
    makeWeather(weather[8], Date(10, Date::Month::JUN, 2015), 19, 15, true,  741, 79);
    makeWeather(weather[9], Date(11, Date::Month::JUN, 2015), 20, 15, true,  738, 80);

    int item = 0;
    do {
        cout << "1. Вывести самый холодный и теплый день.\n"
             << "2. Вывести среднюю температуру за месяц.\n"
             << "3. Вывести количество дней с осадками.\n"
             << "4. Выход\n";

        cin >> item;
        switch (item) {
            case 1: {
                printColdestAndWarmestDays(weather, size);
                break;
            }
            case 2: {
                printAverageTemperatureOfTheMonth(weather, size, Date::Month::JUN);
                break;
            }
            case 3:
                cout << "Count for dates with precipitation: "
                     << countForDatesWithPrecipitation(weather, size, Date::Month::JUN) << endl;
                break;
            case 4:
                return 0;
            default:
                continue;
        }
    } while (item != 4);

    return 0;
}
