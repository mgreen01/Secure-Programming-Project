//
// Author:  Morgan Green
// Date created: 05/04/2021
// Date modified: 05/04/2021
// Title: Student Class Header
// Description: creates the Student Class
#include <string>
#ifndef STUDENT_H
#define STUDENT_H

class Student {
    private:
        std::string student_username;
        std::string student_password; 
    public:
        Student();
        int student_ID;
        std::string student_name;
        std::string student_course;
        void setPassword(std::string stu_pass){
            student_password = stu_pass;
        }
        std::string getPassword () {
            return student_password;
        }

};
#endif