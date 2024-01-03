//
//  main.cpp
//  Perpetual Calendar
//
//  Created by Kyo Mangold on 31.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
#include <cassert>
using namespace std;

// PRE:  a year greater or equal than 1900
// POST: returns whether that year was a leap year
bool is_leap_year(unsigned int year){
     assert(year >= 1900);
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}


// PRE:  a year greater or equal than 1900
// POST: returns the number of days in that year
unsigned int count_days_in_year(unsigned int year){
    assert(year >= 1900);
   int number_of_days_in_year = 365;
    if (is_leap_year(year) == true )
    {
        number_of_days_in_year += 1;
        return number_of_days_in_year;
    }
    else
    {
        return number_of_days_in_year;
    }
}


// PRE:  a month between 1 and 12 and a year greater or equal than 1900
// POST: returns the number of days in the month of that year
unsigned int count_days_in_month(unsigned int month, unsigned int year){
//    assert(((month >= 1) && (month <=12)) && (year >= 1900));
    int number_of_days_in_month = 31;
    switch(month){
        case 1: return number_of_days_in_month; break;
        case 2:
        {
            if (is_leap_year(year) == true)
            {
                number_of_days_in_month -= 2;
                return number_of_days_in_month;
            }
            else
            {
                number_of_days_in_month -=3;
                return number_of_days_in_month;
            }
        } break;
        case 8: return number_of_days_in_month; break;
        case 12: return number_of_days_in_month;break;
        default:
        {
            if ((month % 2 == 0)){
                number_of_days_in_month -= 1;
                return number_of_days_in_month;
            }
            else return number_of_days_in_month;
        } break;
    }
}


// PRE:  n/a
// POST: returns whether the given values represent a valid date
bool is_valid_date(unsigned int day, unsigned int month, unsigned int year){
    if (((day <= count_days_in_month(month, year)) && day >= 1) && ((month >= 1) && (month <= 12)) && year >=1900)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// PRE:  the given values represent a valid date
// POST: returns the number of days between January 1, 1900 and this date
unsigned int count_days(unsigned int day, unsigned int month, unsigned int year){
    assert(is_valid_date(day, month, year) == true);
    int number_of_days_difference = 0;
    
    if (year > 1900)
    {
        for (int i = 1900; i < year; i++)
        {
            if (is_leap_year(i) == true)
                {
                    number_of_days_difference += 366;
                }
            else
                {
                    number_of_days_difference += 365;
                }
        }
        if (month > 1){
            for (int i = 1; i < month; i++){
                number_of_days_difference += count_days_in_month(i, year);
            }
            if (day > 1)
            {
                number_of_days_difference += (day -1);
            }
            else {
                number_of_days_difference += 0;
            }
            
        }
        else { // if the month is the same as the reference month
            number_of_days_difference += (day - 1);
        }
    }
    
    
    else { // if the year is the same as the reference year
        if (month > 1){
            for (int i = 1; i < month; ++i){
                number_of_days_difference += count_days_in_month(i, 1900);
            }
            
        }
        else {
            number_of_days_difference += (day -1);
        }
    }
  
    switch (month){
        case 1: number_of_days_difference += 1; break;
        case 2: {
            if (is_leap_year(year) == true){
                number_of_days_difference += 0;
            }
            else {
            number_of_days_difference += 0;break;
            }
        }
            
        case 3: number_of_days_difference += 1; break;
        case 4: number_of_days_difference += 1; break;
        case 5: number_of_days_difference += 1; break;
        case 6: number_of_days_difference += 1; break;
        case 7: number_of_days_difference += 1; break;
        case 8: number_of_days_difference += 1; break;
        case 9: number_of_days_difference += 1; break;
                case 10: number_of_days_difference += 0; break;
        case 11: number_of_days_difference += 1; break;
        case 12: {
            if (year == 1900) {
                number_of_days_difference += 2;
            }
            else {
                number_of_days_difference += 0;
            }
            
        }break;
        default: number_of_days_difference += 0; break;
    }
    
    return number_of_days_difference;
}



int main() {
    unsigned int day, month, year, weekday;
    cout << "Enter a day: ";
    cin >> day;
    cout << "Enter a month: ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;
  
    if (is_valid_date(day, month, year) == true) {
        int number_of_days;
        number_of_days = count_days(day, month, year);
        weekday = number_of_days % 7;
        
        cout << weekday << endl;
        
        switch(weekday){
            case 1: cout << "Monday" << endl; break;
            case 2: cout << "Tuesday" << endl; break;
            case 3: cout << "Wednesday" << endl; break;
            case 4: cout << "Thursday" << endl; break;
            case 5: cout << "Friday" << endl; break;
            case 6: cout << "Saturday" << endl; break;
            case 0: cout << "Sunday" << endl; break;
            default: return 0;
        }
        return 0;
    }
    else
    {
      cout << "invalid date" << endl;
        return 0;
    }
}

