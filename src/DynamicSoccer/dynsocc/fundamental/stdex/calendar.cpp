#include "calendar.h"

#include <string.h>
#include <strings.h>
#include <string>
#include <vector>
#include "algorithm.hpp"


using namespace dynsocc;
using namespace std;

string azWeekday[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int rotate_fw_weekday(int nWeekday) {
    nWeekday++;

    if (nWeekday == 7) {
        nWeekday = 0;
    }
    return nWeekday;
}

int rotate_bw_weekday(int nWeekday) {
    nWeekday--;

    if (nWeekday < 0) {
        nWeekday = 6;
    }
    return nWeekday;
}

Calendar::Calendar() {
    yearcount = 0;
}

int Calendar::Copy54Int(int* pdest, int* psource) {
    memcpy(pdest, psource, sizeof(int)*54);
    return 0;
}

int Calendar::printint2D(/*int[][54] a*/) {
    return 0;
}

int Calendar::build_solar_years(int year, int month, int day, const char* day_of_week) {
    /*============================================================
     * 
     *============================================================*/

    /*============================================================
     *  API1. Year/Month/Day => Weekday
     *  API2. The Next Weekday StartingFrom Year/Month/Day
     *  API3. The Nth-Next Weekday StartingFrom Year/Month/Day
     *============================================================*/

    // API1. 
    /* One Solar calndar Year */
    

    /*------------------------------
        BuildOneYear (BOY)
        BOY1. 
            AnchorDay 
        BOY2. 
            AnchorDay++ => EndYear
        BOY3. 
            AnchorDay-- => BeginningOfYear

        Output:
            weekr[54]

        BOY4. 
            WeekID = ceil(DayOfYear / 7)
     *------------------------------*/
    int doy = date_to_dayofyear(year, month, day); // Day of Year
    int wdy = Weekday(day_of_week);
    int doy_sd = doy + (6 - wdy); // This Sunday 
    int doy_1sd;  // The first sunday in year
    int yweekr[54];  // yweekr[3] = 21 <=> The end of week 3 is the 21-th day of year
    int nweek = 0;
    int nLeap = (year % 4 == 0);

    if (doy_sd > azYearDay[nLeap]) { 
        doy_sd -= 7; 
    }

    doy_1sd = doy_sd % 7;  // The 1st Sunday
    if (doy_1sd == 0) {
        doy_1sd = 7;
    }

    int i = doy_1sd;
    int j = 1;

    while (i < azYearDay[nLeap]) {
        yweekr[j++] = i;
        i += 7;
    }
    nweek = j;

    // Skip
    /*
    algorithm::put_map<int, int*>(  
        year,   // Key
        yweekr, // Value
        yearl,  // Map Key
        year_weekr,  // Map Vaue
        Copy54Int,    
        yearcount);
    */

    for (i = 1; i<=5 ; i++) {
        int yearb = year - i;
        int yearn = year + i;
    }

    // int dow = Weekday(weekday);
    // int doy = date_to_dayofyear(year, month, day);

    return 0;
}

int Calendar::Weekday(const char* weekday) {

    int nFound = -1;
    for (int i=0; i<7; i++) {
        if (strcasecmp(azWeekday[i].c_str(), weekday) == 0) {
            nFound = i;
            break;
        }
    }

    return nFound;
}

int Calendar::date_to_dayofyear(int year, int month, int day) {
    int nLeap = (year % 4 == 0);

    return azMonthByDoY[nLeap][month-1] + day;
}

int Calendar::weeknumber(int dayofyear, int* yweeked, int nWeek) {

    /* 
        yweeked[] { 0, 3, 10, 17, ... }
     */

    int i = 1;
    int iW = -1;
    while ( i < nWeek) {
        if (yweeked[i-1] < dayofyear && yweeked[i] >= dayofyear) {
            iW = i;
            break;
        }
        i++;
    }

    return iW;
}


std::string Calendar::weekday_of_date(int year, int month, int day, int* yweeked, int nWeek) {

    int i = 0;
    int j = 0;

    int doy = date_to_dayofyear(year, month, day);

    int weeknum = weeknumber(doy, yweeked, nWeek);

    int isun = yweeked[weeknum]; // Sunday Index
    int ibegin = yweeked[weeknum-1] + 1;
    
    /*------------------------------
        weeknum=1 (The firstweek)
            => The end of week  is Sunday
                (yweek[weeknum])
        weeknum=nWeek (The last week)
            => The beginning of week is Monday
                (yweek[weenum-1] + 1)
        weeknum in [2,nWeek-1] (Middle week)
            => The beginning of the week is Monday
                The end of the week is Sunday
     *------------------------------*/
    int iwd = (doy - yweeked[weeknum-1] - 1);  // Index-weekday

    if (weeknum == 1) {
        iwd = 6 /* sunday */ - (yweeked[weeknum] - doy);
    }
    else {
        iwd = 0 /* Monday */ + (doy - yweeked[weeknum-1] - 1);
    }
    
    return azWeekday[iwd];
}