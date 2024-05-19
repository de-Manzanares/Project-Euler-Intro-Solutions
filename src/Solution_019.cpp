//  Solution 19
//  Copyright (c) 2024. de-Manzanares
//  Contact: git.in.touch@dmanz.org
//
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
//  https://projecteuler.net/problem=19

#include <cstdint>
#include <iostream>

enum class Day : uint8_t {
    Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

Day& operator++(Day& day)
{
    if (day == Day::Saturday) {
        day = Day::Sunday;
    }
    else {
        day = static_cast<Day>(static_cast<uint8_t>(day) + 1);
    }
    return day;
}

Day operator++(Day& day, int)
{
    Day copy = day;
    ++day;
    return copy;
}

Day& operator--(Day& day)
{
    if (day == Day::Sunday) {
        day = Day::Saturday;
    }
    else {
        day = static_cast<Day>(static_cast<uint8_t>(day) - 1);
    }
    return day;
}

Day operator--(Day& day, int)
{
    Day copy = day;
    --day;
    return copy;
}

Day operator+(Day day, int n)
{
    for (int i = 0; i < n; i++) {
        ++day;
    }
    return day;
}

Day& operator+=(Day& day, int n)
{
    return (day = day + n);
}

Day operator-(Day day, int n)
{
    for (int i = 0; i < n; i++) {
        --day;
    }
    return day;
}

Day& operator-=(Day& day, int n)
{
    return (day = day - n);
}

std::ostream& operator<<(std::ostream& os, const Day& day)
{
    switch (day) {
    case Day::Sunday :os << "Sunday";
        break;
    case Day::Monday :os << "Monday";
        break;
    case Day::Tuesday :os << "Tuesday";
        break;
    case Day::Wednesday :os << "Wednesday";
        break;
    case Day::Thursday :os << "Thursday";
        break;
    case Day::Friday :os << "Friday";
        break;
    case Day::Saturday :os << "Saturday";
        break;
    }
    return os;
}

class Month {
public:
    Month();
    Month(int nth_month, int year);
    Month& set_month(int nth_month, int _year);
    Month& operator++();
    Month& operator--();

    int year() const { return current_year; }

    int month() const { return current_month; }

    int length() const { return days_in_month; }

private:
    int current_year;
    int current_month = 1;
    int days_in_month = 31;
};

Month::Month()
{
    current_year = 1900;
    current_month = 1;
    days_in_month = 31;
}

Month::Month(int nth_month, int year)
{
    set_month(nth_month, year);
}

Month& Month::set_month(int nth_month, int _year)
{
    current_year = _year;
    current_month = nth_month;
    switch (current_month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: days_in_month = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11: days_in_month = 30;
        break;
    case 2:
        if ((current_year % 4 == 0 && current_year % 100 != 0)
                || (current_year % 400 == 0)) {
            days_in_month = 29;
        }
        else {
            days_in_month = 28;
        }
        break;
    }
    return *this;
}

Month& Month::operator++()
{
    if (current_month == 12) {
        set_month(1, ++current_year);
    }
    else {
        set_month(++current_month, current_year);
    }
    return *this;
}

Month& Month::operator--()
{
    if (current_month == 1) {
        set_month(12, --current_year);
    }
    else {
        set_month(--current_month, current_year);
    }
    return *this;
}

class Date {
public:
    Date();
    Date(int _year, int _month, int _day_n);
    Day set_day();
    Date& operator++();
    Date& operator--();
    bool operator>(Date& rhs);
    bool operator==(Date& rhs);
    int operator-(Date& rhs);
private:
    Month month;
    int day_n;
    Day day;
};

Date::Date()
{
    month.set_month(5, 2024);
    day_n = 19;
    day = Day::Sunday;
}

Date& Date::operator++()
{
    if (day_n == month.length()) {
        day_n = 1;
        ++month;
    }
    else {
        ++day_n;
    }
    return *this;
}

Date& Date::operator--()
{
    if (day_n == 1) {
        --month;
        day_n = month.length();
    }
    else {
        --day_n;
    }
    return *this;
}

bool Date::operator==(Date& rhs)
{
    return (month.year() == rhs.month.year()
            && month.month() == rhs.month.month()
            && day_n == rhs.day_n);
}

bool Date::operator>(Date& rhs)
{
    return (
            month.year() > rhs.month.year()
                    || month.year() == rhs.month.year()
                            && month.month() > rhs.month.month()
                    || month.year() == rhs.month.year()
                            && month.month() == rhs.month.month()
                            && day_n > rhs.day_n
    );
}

Day Date::set_day()
{
    Date reference;
    int difference;
    if (reference > *this) {
        difference = reference - *this;
        day = reference.day + (difference % 7);
    }
    else {
        difference = *this - reference;
        day = reference.day - (difference % 7);
    }
    return day;
}

Date::Date(int _year, int _month, int _day_n)
{
    month.set_month(_month, _year);
    if (_day_n < 1) {
        day_n = 1;
    }
    else if (_day_n > month.length()) {
        day_n = month.length();
    }
    else {
        day_n = _day_n;
    }
    day = set_day();
}

int Date::operator-(Date& rhs)
{
    int difference = 0;     // difference in days
    Date copy = *this;
    while (month.year() != rhs.month.year()) {
        --copy;
        ++difference;
    }
    while (month.month() != rhs.month.month()) {
        --copy;
        ++difference;
    }
    while (day_n != rhs.day_n) {
        --copy;
        ++difference;
    }

    return difference;
}

int main()
{
    Date today;
    Date future(2024, 05, 21);
    std::cout << future - today;
}
