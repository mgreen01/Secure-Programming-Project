//This is a blank file
#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
using namespace std;

int length = 0;

class Crypto {
    private:
        string plain_password;
        string encrypted_password;
    public:
        void setPassword(string p){
            plain_password = p;
        }
        string getPassword() {
            return plain_password;
        }
};

class Time {
   public:
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
   string clock_day;
};

class User {
    public:
    string username;
    int age;
    int account_type;
    string password;
};

int main () {
    cout << "Please enter a new username: " << endl;
    User new_user;
    cin >> new_user.username;
    cout << "Please enter your age: " << endl;
    cin >> new_user.age;
    cout << "Please enter a new password: " << endl;
    cin >> new_user.password;

    for (int i= 0; new_user.password[i] !='\0'; i++) {
        length++;
    }
    
    
    cout << length << endl;

    Time curr_time;

    curr_time.clock_hour = to_string(curr_time.hour);
    curr_time.clock_min = to_string(curr_time.min);
    curr_time.clock_sec = to_string(curr_time.sec);
    curr_time.clock_month = to_string(curr_time.month);
    curr_time.clock_year = to_string(curr_time.year);
    curr_time.clock_day = to_string (curr_time.day);

   if (curr_time.hour <= 9) {
      curr_time.clock_hour = '0' + curr_time.clock_hour;
   }

   if (curr_time.min <= 9) {
      curr_time.clock_min = '0' + curr_time.clock_min;
   }

   if (curr_time.sec <= 9) {
      curr_time.clock_sec = '0' + curr_time.clock_sec;
   }

   if (curr_time.month <= 9) {
       curr_time.clock_month = '0' + curr_time.clock_month;
   }

   if (curr_time.day <= 9) {
       curr_time.clock_day = '0' + curr_time.clock_day;
   }

    Crypto new_password;
    new_password.setPassword(new_user.password);
    
    return 0;
    
};