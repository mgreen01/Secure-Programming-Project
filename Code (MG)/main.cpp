//Created by: Morgan Green
//Date Created: 06th April 2021 20:04:29
//Date Modified: 21st April 2021 18:47:27
#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <limits>
#include <stdio.h>
using namespace std;
//first cipher lookup table
map <char,int> dict1;
//second cipher lookup table
map <int,char> dict2;

//Provides the current based on Unix Time 
class Time {
   public:
   time_t now = time(0);

   tm *ltm = localtime(&now);
   
   int year = 1900 + ltm-> tm_year;
   int month = 1 + ltm->tm_mon;
   int day = ltm->tm_mday;
   
   
   string clock_month;
   string clock_year;
   string clock_day;
};
//This class provides information about the user's username, password, account type()
class User {
    private:
        string password;
    public:
        string username;
        string age;
        int account_type;
        void setuserpassword(string userpass){
            password = userpass;
        }
        string getuserpassword(){
            return password;
        }
        ifstream Dupcheck;
};

class Student {
    private:
        string student_username;
        string student_password;
   public:
        string student_name;
        string age;
        string student_course;
        void setstudentusername(string stuuser){
            student_username = stuuser;
        }
        string getstudentusername() {
            return student_username;
        }
        void setstudentpassword(string stupass){
            student_password = stupass;
        }
        string getstudentpassword(){
            return student_password;
        }
        //void register_student(){
        //    string password = getstudentpassword();
        //    string username = getstudentusername(); 
        //}
     
};

class Lecturer {
    private:
        string lecturer_password;
    public:
        ofstream lecturerannou1;
        ifstream lecturerannou;
    void setlecturerpassword(string lecpassword){
        lecturer_password = lecpassword;
    }
    string getlecturerpassword(){
        return lecturer_password;
    }
};

class Admin {
    public:
        ifstream adminlogin;
        ofstream adminannou1;
        ifstream adminannou;
};
//class for working out values within the encryption algorithm
class Crypto {
    private:
        string plain_password;
        string encrypted_password;
        string encrypt1;
        string encrypt2;
        string encrypt3;
    public:
        void setPlainPassword(string p){
            plain_password = p;
        }
        string getPlainPassword() {
            return plain_password;
        }
        void setEncryptedPassword (string ep){
            encrypted_password = ep;
        }
        string getEncryptedPassword() {
            return encrypted_password;
        }
        void setEncrypt1(string en1) {
            encrypt1 = en1;
        }
        string getEncrypt1(){
            return encrypt1;
        }
        void setEncrypt2(string en2) {
            encrypt2 = en2;
        }
        string getEncrypt2() {
            return encrypt2;
        }
        void setEncrypt3(string en3) {
            encrypt3 = en3;
        }
        string getEncrypt3() {
            return encrypt3;
        }
        void create_dict()
        {
            for(int i = 1; i < 27; i++)
                dict1[char(64 + i)] = i;
            
            dict2[0] = 'Z';

            for(int i = 1; i < 26; i++)
                dict2[i] = char(64 + i);

            return;    
        }
};

Crypto new_password;

//String encryption function
string encrypt(string message, int shift)
{
    string passcip = "";
    for(int i = 0; i < message.size(); i++)
    {
        if(message[i] != ' ')
        {
            int num = (dict1[message[i]] + shift) % 26;

            passcip += dict2[num];
        }
        else
        {
            passcip += " ";
        }
    }
    return passcip;
}

int main () {
    Admin syslogin;
    Student stulogin;
    Lecturer lecturlogin;
    new_password.create_dict();
    int user_input;
    int length;
    string password_confirmation;
    string password_input;
    string adminuser;
    string adminage;
    string adminpassword;
    string password_file;
    Time curr_time;
    #define MAX_ADMIN_LEN 255
    #define MAX_LECTURER_LEN 255

    //Time Format
    curr_time.clock_month = to_string(curr_time.month);
    curr_time.clock_year = to_string(curr_time.year);
    curr_time.clock_day = to_string (curr_time.day);

   if (curr_time.month <= 9) {
       curr_time.clock_month = '0' + curr_time.clock_month;
   }

   if (curr_time.day <= 9) {
       curr_time.clock_day = '0' + curr_time.clock_day;
   }

    User existing_user;
    Crypto existing_password;
    cout << "Please enter your username: " << endl;
    cin >> existing_user.username;
    cout << "Please enter your password: " << endl;
    cin >> password_input;
    existing_password.setPlainPassword(password_input);
    existing_password.setEncrypt1(existing_password.getPlainPassword());

    ifstream user_file;
    string user_name2 = existing_user.username + ".txt";
    user_file.open(user_name2);
    user_file >> existing_user.account_type;
    user_file >> existing_user.age;
    user_file >> password_file;
    user_file.close();

    string message = existing_password.getEncrypt1();
    int shift = 13;

    existing_password.setEncrypt2(encrypt(message, shift));

    existing_password.setEncrypt3(curr_time.clock_month + curr_time.clock_year + existing_user.age + existing_password.getEncrypt2());

    string res = existing_password.getEncrypt3();

    int len = existing_password.getEncrypt3().length();

    int n=len-1;
    for(int i=0;i<(len/2);i++){
        swap(res[i],res[n]);
        n = n-1;
    }

    existing_password.setEncryptedPassword(res);

    string encryptinput = existing_password.getEncryptedPassword(); 

    //Student Menu
    if (encryptinput == password_file && existing_user.account_type == 1){
        Admin studentuser;
        Lecturer studentview;
        string studentadminannou;
        string Lecturernameannou;
        int stumenu;
        cout << "Welcome " << existing_user.username << endl;
        //Admin Announcement Display
        studentuser.adminannou.open("RE.txt");
        if(studentuser.adminannou.is_open()){
            cout << "Admin announcment: " << endl;
            while (getline(studentuser.adminannou,studentadminannou))
            {
                cout << studentadminannou << endl;
            }
        }
        studentuser.adminannou.close();
        //Module Annoucement Display
        studentview.lecturerannou.open("LecturerAnnouncment.txt");
        if (studentview.lecturerannou.is_open()){
            cout << "Lecturer announcment: " << endl;
            while (getline(studentview.lecturerannou, Lecturernameannou))
            {
                cout << Lecturernameannou << endl;
            }
        }
        studentview.lecturerannou.close();
        //Main Student Menu
        cout << "Student Menu: " << endl;
        cout << "1. View Grades" << endl;
        cout << "2. Extra Activites" << endl;
        cout << "3. Employment Opportunities" << endl;
        cout << "4. Logout" << endl;
        cin >> stumenu;
        //Grades Menu
        while (stumenu == 1){
            cout << "No grades available yet. Keep your eyes peeled" << endl;
            cout << "Student Menu: " << endl;
            cout << "1. View Grades" << endl;
            cout << "2. Extra Activites" << endl;
            cout << "3. Employment Opportunities" << endl;
            cout << "4. Logout" << endl;
            cin >> stumenu;
        }
        //Extra Activites Menu
        while (stumenu == 2){
            cout << "2021 Summer CTF Teams" << endl;
            cout << "Maths Club" << endl;
            cout << "USW Rugby Team" << endl;
            cout << "1. View Grades" << endl;
            cout << "2. Extra Activites" << endl;
            cout << "3. Employment Opportunities" << endl;
            cout << "4. Logout" << endl;
            cin >> stumenu;
        }
        //Employment Opportunities Menu
        while (stumenu == 3){
            cout << "Dragon Security: Paid Internship 2021/2022" << endl;
            cout << "Welsh Government: Graduate Security Engineer" << endl;
            cout << "Cyber-Not-Aware: Security Researcher " << endl;
            cout << "1. View Grades" << endl;
            cout << "2. Extra Activites" << endl;
            cout << "3. Employment Opportunities" << endl;
            cout << "4. Logout" << endl;
            cin >> stumenu;
        }
        //User Logout
        if (stumenu == 4){
            return 0;
        }
    }
    //Lecturer System Interface
    if(encryptinput == password_file && existing_user.account_type == 2){
        int lecchoice;
        Admin LecturerUser;
        string lectureradminannou;
        string lecturername;
        Lecturer lecinfo;
        cout << "Welcome " << existing_user.username << endl;
        LecturerUser.adminannou.open("RE.txt");
        if(LecturerUser.adminannou.is_open()){
            cout << "Admin announcment: " << endl;
            while (getline(LecturerUser.adminannou,lectureradminannou))
            {
                cout << lectureradminannou << endl;
            }
        }
        LecturerUser.adminannou.close();
        //Lecturer Main Menu
        cout << "Lecturer Menu: " << endl;
        cout << "1. Set Assignments" << endl;
        cout << "2. Submit Markings" << endl;
        cout << "3. Set Module Announcements" << endl;
        cout << "4. Logout" << endl;
        cin >> lecchoice; 
        //Lecturer Set Assignments Menu
        while (lecchoice == 1){
            cout << "You cannot Set Assignments Yet" << endl;
            cout << "Lecturer Menu: " << endl;
            cout << "1. Set Assignments" << endl;
            cout << "2. Submit Markings" << endl;
            cout << "3. Set Module Announcments" << endl;
            cout << "4. Logout" << endl;
            cin >> lecchoice; 
        }
        //Marking Submission Menu
        while (lecchoice == 2) {
            cout << "You cannot submit markings since there are no Assignments Set" << endl;
            cout << "Lecturer Menu: " << endl;
            cout << "1. Set Assignments" << endl;
            cout << "2. Submit Markings" << endl;
            cout << "3. Set Module Announcments" << endl;
            cout << "4. Logout" << endl;
            cin >> lecchoice;
        }

        //Module Announcement Menu
        if (lecchoice == 3) {
          lecinfo.lecturerannou1.open("LecturerAnnouncment.txt");
          char lec[MAX_LECTURER_LEN];
          cout << "Enter the announcement (Press '*' on your keyboard): " << endl;
          lecinfo.lecturerannou1 << existing_user.username << endl; 
          cin.getline(lec, MAX_LECTURER_LEN, '*');
          lecinfo.lecturerannou1 << lec << endl;
          lecinfo.lecturerannou1.close();
          cout << "Lecturer Menu: " << endl;
          cout << "1. Set Assignments" << endl;
          cout << "2. Submit Markings" << endl;
          cout << "3. Set Module Announcments" << endl;
          cout << "4. Logout" << endl;
          cin >> lecchoice;
        }

        //System Logout
        if (lecchoice == 4){
            return 0;
        }



    }

    //admin menu/interface
    if (encryptinput == password_file && existing_user.account_type == 3){
      Admin rootuser;
      int adminmenu;
      //Admin system menu 
      cout << "Admin Menu:" << endl;
      cout << "1. Make a system announcement: " << endl;
      cout << "2. Add an account" << endl;
      cin >> adminmenu;
      //System Announcement Menu
      if (adminmenu == 1){
          rootuser.adminannou1.open("RE.txt");
          char admininfo[MAX_ADMIN_LEN];
          cout << "Enter the announcement (Press '*' on your keyboard): " << endl;
          cin.getline(admininfo, MAX_ADMIN_LEN, '*');
          rootuser.adminannou1 << admininfo << endl;
          rootuser.adminannou1.close();
          return 0;
       }
       //Account Creation Menu
       if (adminmenu == 2) {
            User new_account;
            ofstream outputFile;
            string UserDupcheck;
            cout << "Select account type: 1. Student or 2. Lecturer: " << endl;
            cin >> new_account.account_type;
            //Student Account Creation Menu
            if (new_account.account_type == 1){
                Student new_student;
                cout << "Please enter a new username: " << endl;
                cin >> new_account.username;
                string UserDupcheck = new_account.username + ".txt";
                new_account.Dupcheck.open(UserDupcheck);
                if (new_account.Dupcheck.is_open()){
                    new_account.Dupcheck.close();
                    cout << "Username Already Exists, Please enter a new username: " << endl;
                    cin >> new_account.username;
                }
                cout << "Please enter the Student's Age: " << endl;
                cin >> new_account.age;
                cout << "Please enter a new password: " << endl;
                cin >> password_input;
                new_student.setstudentpassword(password_input);
                cout << "Please confirm the new password:"  << endl;
                //Student Password Confirmation
                cin >> password_confirmation;
                while (password_confirmation != new_student.getstudentpassword()){
                    cout << "Please try again: " << endl;
                    cin >> password_input;
                    new_student.setstudentpassword(password_input);
                    cout << "Please confirm the new password:"  << endl;
                    cin >> password_confirmation;
                }
                //Student Password Encryption Algorithm
                new_password.setPlainPassword(password_input);
                new_password.setEncrypt1(new_password.getPlainPassword());

                string message = new_password.getEncrypt1();
                int shift = 13;
                
                new_password.setEncrypt2(encrypt(message, shift));
                new_password.setEncrypt3(curr_time.clock_month + curr_time.clock_year + new_account.age + new_password.getEncrypt2());
                string res1 = new_password.getEncrypt3();
                int len1 = res1.length();
                int n1=len1-1;
                for(int i=0;i<(len1/2);i++){
                    swap(res1[i],res1[n1]);
                    n1 = n1-1;
                }
                new_password.setEncryptedPassword(res1);

                //Student Login Info Output
                string encryptpass = new_password.getEncryptedPassword();
                
                string new_username = new_account.username + ".txt";

                outputFile.open(new_username);
                outputFile << new_account.account_type << endl;
                outputFile << new_account.age << endl;
                outputFile << encryptpass << endl;
                outputFile.close();
            }
            if (new_account.account_type == 2) {
                //Lecturer Account Creation Menu
                Lecturer new_lecturer;
                cout << "Enter the Lecturer's Username: " << endl;
                cin >> new_account.username;
                string UserDupcheck = new_account.username + ".txt";
                //Lecturer Username Duplicate Checker
                new_account.Dupcheck.open(UserDupcheck);
                if (new_account.Dupcheck.is_open()){
                    new_account.Dupcheck.close();
                    cout << "Username Already Exists, Please enter a new username: " << endl;
                    cin >> new_account.username;
                }
                cout << "Please enter the lecturer's age" << endl;
                cin >> new_account.age;
                cout << "Please enter a new password: " << endl;
                cin >> password_input;
                cout << "Please confirm the new password: " << endl;
                cin >> password_confirmation;
                //Lecturer Password Confirmation
                new_lecturer.setlecturerpassword(password_confirmation);
                while(password_confirmation != new_lecturer.getlecturerpassword()){
                    cout << "Please try again: " << endl;
                    cin >> password_input;
                    cout << "Please confirm the new password: " << endl;
                    cin >> password_confirmation;
                }
                //Lecturer Password Encryption
                new_password.setPlainPassword(password_confirmation);
                new_password.setEncrypt1(new_password.getPlainPassword());

                string message = new_password.getEncrypt1();
                int shift = 13;

                new_password.setEncrypt2(encrypt(message,shift));
                new_password.setEncrypt3(curr_time.clock_month + curr_time.clock_year + new_account.age + new_password.getEncrypt2());
                
                string res1 = new_password.getEncrypt3();
                int len1 = res1.length();
                int n1=len1-1;
                for(int i=0;i<(len1/2);i++){
                    swap(res1[i],res1[n1]);
                    n1 = n1-1;
                }
                new_password.setEncryptedPassword(res1);

                //Lecturer Login Info output
                string encryptpass = new_password.getEncryptedPassword();
                
                string new_username = new_account.username + ".txt";

                outputFile.open(new_username);
                outputFile << new_account.account_type << endl;
                outputFile << new_account.age << endl;
                outputFile << encryptpass << endl;
                outputFile.close();
            }    
       }
    }
};

