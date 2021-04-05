#include <string>
#ifndef STUDENT_H
#define STUDENT_H

class Student {
    public:
        int student_ID;
        std::string student_name;
        std::string student_course;
    private:
        std::string student_username;
        std::string student_password;
    
};
#endif