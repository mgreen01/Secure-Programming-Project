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



int main () {
    cout << "Hello world";
}