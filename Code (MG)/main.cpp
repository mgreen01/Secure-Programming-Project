#include <iostream>
using namespace std;

class Student {
   public:
        int student_ID;
        string student_name;
        string student_course;
   private:
        string student_username;
        string student_password; 
};

class Lecturer {
    public:
        int lecturer_ID;
        string lecturer_name;
        string lecturer_modules;
        void moduleAnnouncement();
    private:
        string lecturer_username;
        string lecturer_password;
};

class User {
    string username;
    int age;
    string account_type;
    string password;
};

class Admin {
    string admin_username;
    string admin_password;
    void systemAnnouncement();
};

class Crypto {
    string plain_password;
    string encrypted_password;
};



int main () {
    Student Teststu1;
    Teststu1.student_ID = 1;
    Teststu1.student_name = "Joseph James";
    Teststu1.student_course = "Computer Security";
    Teststu1.student_username = "23032394";
    Teststu1.student_password = "?";


};