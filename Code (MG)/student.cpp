//
// Author: Morgan Green


#include <iostream>
#include <string>
#include "Student.h"


Student::Student(){
        std::cout << "Please enter the student's username: ";
        std::cin >> student_username;
        std::cout << "Please enter the student's name: ";
        std::cin >> student_name;
        std::cout << "Please enter the student's password: ";
        std::cin >> student_password;
        std::cout << "Please enter the student's course: ";
        std::cin >> student_course;
        student_ID = rand() % 100;

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







