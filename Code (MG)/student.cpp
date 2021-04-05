//
// Author: Morgan Green


#include <iostream>
#include <string>
#include "Student.h"


Student::Student(){



}

std::string Student::getPassword(){
        return student_password;
}

void Student::setPassword(std::string stu_pass){
        student_password = stu_pass;
}

std::string Student::getUsername(){
        return student_username;
}


void Student::setUsername(std::string stu_username){
        student_username = stu_username;        
}







