#include "calendar.h"

#include <strings.h>
#include <string>
#include <vector>


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
    nyear_week = 0;
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

    // string azWeekday[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    bool bLeap = (year % 4 == 0); // Leap Year?
    int nYearS = year - 4;
    int nyearE = year + 4;

    int azIndex[3670];
    int azMonth[120];
    int azDay[3660];
    int azYear[10];

    // API1. 
    /*------------------------------
        Structure: Month: 

        azWdOY: Weekdays of Year
        azWdOY[366].
        MonthL[12]
        MonthR[12]

        i-th => Month => BinarySearch 
        i-th => Day-Of-Month => 
     *------------------------------*/

    /* One Solar calndar Year */
    int yweekr[54];  // yweekr[3] = 21 <=> The end of week 3 is the 21-th day of year
    int nLeap = (year % 4 == 0);


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