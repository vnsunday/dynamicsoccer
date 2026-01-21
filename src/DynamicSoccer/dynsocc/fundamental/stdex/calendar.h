#ifndef DYNSOCC_FUNDAMENTAL_STDEX_CALENDAR_H_
#define DYNSOCC_FUNDAMENTAL_STDEX_CALENDAR_H_

#include <string>

namespace dynsocc 
{
    std::string azWeekday[7]; // = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    int azMonthSize[2][13] = { 
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, 
        { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };

    // Month  by Day of Year
    int azMonthByDoY[2][13] = {
        { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
        { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
    };

    class Calendar 
    {
    private:
        /* Map */
        int year_weekr[100][54];
        int year_weekl[100];
        int yearcount;

    public:

        Calendar();

        int build_solar_years(int year, int month, int day, const char* day_of_week);

        int Weekday(const char* weekday);

        int date_to_dayofyear(int year, int month, int day);

        int weeknumber(int dayofyear, int* yweeked, int nWeek); /* 1-366 */ 

        std::string weekday_of_date(int year, int month, int day, int* yweeked, int nWeek);

        // std::string find_date_by_weekday(const char*weekday, int year, int month, int day);

        
    };
}

#endif 