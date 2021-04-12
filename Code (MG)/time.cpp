#include <iostream>
#include <ctime>

using namespace std;

int main () {
   // current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);
   
   int hour = ltm->tm_hour;
   int min = ltm->tm_min;
   int sec = ltm->tm_sec;
   int year = 1900 + ltm-> tm_year;
   int month = 1 + ltm->tm_mon;
   int day = ltm->tm_mday;
   
   string clock_hour;
   string clock_min;
   string clock_sec;
   string clock_month;
   string clock_year;

   clock_hour = to_string(hour);
   clock_min = to_string(min);
   clock_sec = to_string(sec);
   clock_month = to_string(month);
   clock_year = to_string(year);
   clock_day = to_string(day);


   if (hour <= 9) {
      clock_hour = '0' + clock_hour;
   }

   if (min <= 9) {
      clock_min = '0' + clock_min;
   }

   if (sec <= 9) {
      clock_sec = '0' + clock_sec;
   }

   if (month <= 9) {
      clock_month = '0' + clock_month;
   }



   // print various components of tm structure.
   cout << "Year:" << 1900 + ltm->tm_year<<endl;
   cout << "Month: "<< clock_month << endl;
   cout << "Day: "<<  ltm->tm_mday << endl;
   cout << clock_hour << ":";
   cout << clock_min << ":";
   cout << clock_sec << endl;
};