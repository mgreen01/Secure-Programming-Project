#include <iostream>
using namespace std;
    // Student user class
    class Student{
        public:
            int student_ID;
            string student_name;  
            string student_course;
            string student_username;

        private:
            string student_password;
    public:
        // Password setter 
        void setPassword (string set_stu_pass) {
            student_password = set_stu_pass;
        }
        string getPassword() {
            return student_password;
        }

    };
int main()
{
    //Student test account 1 
    Student student1;
    student1.student_ID = 1;
    student1.student_name = "Morgan Green";
    student1.student_course = "Computer Security";
    student1.student_username = "MGreen";
    student1.student_password = "9m5mgm0d564m5609?";
    //Student test account 2
    Student student2;
    student2.student_ID = 2;
    student2.student_name = "Joe Bloggs";
    student2.student_course = "Computer Foresnics";
    student2.student_username = "JoeB";
    student2.student_password = "8m45b46biokwer403424309";
    //Student test account 3
    Student student3;
    student3.student_ID = 3;
    student3.student_name = "Westman Long";
    student3.student_course = "Computer Science";
    student3.student_username = "Log1";
    student3.student_password = "84hntbobtongnfgmf:@:}:_RE)_R)";
};
