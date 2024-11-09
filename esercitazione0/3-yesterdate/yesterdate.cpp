

#include "yesterdate.hpp"


bool checkDate (unsigned year, unsigned month, unsigned day){
    const unsigned days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (year >= 1 && month >= 1 && month <= 12 && day >= 1 && days[month-1] >= day ) ||
    ( ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) && month == 2 && day == 29);
}


void nextDate(unsigned& year, unsigned& month, unsigned& day){
    if (checkDate(year, month, day + 1))
        day++;
    else{
        day = 1;
        if (month == 12)
        {
            month = 1;
            year++;
        }
        else
            month++; 
    }
}

void prevDate(unsigned& year, unsigned& month, unsigned& day){
    int d;
    if (day == 1){
        if(month == 1) year--;
        month = ( (month - 2) % 12 ) + 1;
        for(d = 31; !checkDate(year, month, d); d--);
        day = d;
    }
    else if( day > 1 && day <= 31)
        day--;
}
