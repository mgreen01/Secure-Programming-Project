//This is a blank file
#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <limits>
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
//This class provides information about the user's username, password, account type()
class User {
    private:
        string password;
    public:
        string username;
        string age;
        string account_type;
        void setuserpassword(string userpass){
            password = userpass;
        }
        string getuserpassword(){
            return password;
    }
};

class Student {
    private:
        string student_username;
        string student_password;
   public:
        int student_ID;
        string student_name;
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
        void register_student(){
            string password = getstudentpassword();
            string username = getstudentusername(); 
        }
     
};

class Lecturer {
    private:
        string lecturer_username;
        string lecturer_password;
    public:
        int lecturer_ID;
        string lecturer_name;
        string lecturer_modules;
        void moduleAnnouncement();
};

class Admin {
    private:
        string admin_username;
        string admin_age;
        string admin_password;
    public:
        void setadminusername (string adminuser){
            admin_username = adminuser;
        }
        string getadminusername(){
            return admin_username;
        }
        void setadminage (string adminage){
            admin_age = adminage;
        }
        string getadminage(){
            return admin_age;
        }
        void setadminpassword (string adminpass){
            admin_password = adminpass; 
        }
        string getadminpassword(){
            return admin_password;
        }
        ifstream adminlogin;
        ofstream adminannou1;
        ifstream adminannou;
        string admininput;
};

class Crypto {
    private:
        string plain_password;
        string encrypted_password;
        string encrypt1;
        string encrypt2;
        string encrypt3;
        string decryption1;
        string decryption2;
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
        void setDecrypt1(string de1) {
            decryption1 = de1;
        }
        string getDecrypt1() {
            return decryption1;
        }
        void setDecrypt2(string de2) {
            decryption2 = de2;
        }
        string getDecrypt2() {
            return decryption2;
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
    new_password.create_dict();
    int user_input;
    int length;
    string stu_type = "Student";
    string admin_type = "Admin";
    string Lecturer_type = "Lecturer";
    string password_confirmation;
    string password_input;
    string adminuser;
    string adminage;
    string adminpassword;
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
    syslogin.adminlogin.open("admin.txt");

    syslogin.adminlogin >> adminuser;

    syslogin.adminlogin >> adminage;

    syslogin.adminlogin >> adminpassword;

    syslogin.adminlogin.close();

    cout << adminuser << endl;

    cout << adminpassword << endl;

    cout << "1. Log in or 2. Create Account: " << endl;
    cin >> user_input;
    while (user_input > 2) {
        cout << "Please pick 1 or 2: " << endl;
        cin >> user_input;
    }

    if (user_input == 1) {
        User existing_user;
        Crypto existing_password;
        cout << "Please enter your username: " << endl;
        cin >> existing_user.username;
        cout << "Please enter your password: " << endl;
        cin >> password_input;
        existing_password.setPlainPassword(password_input);
        existing_password.setEncrypt1(existing_password.getPlainPassword());

        string message = existing_password.getEncrypt1();
        int shift = 13;

        existing_password.setEncrypt2(encrypt(message, shift));

        existing_password.setEncrypt3(curr_time.clock_month + curr_time.clock_year + adminage + existing_password.getEncrypt2());

        string res = existing_password.getEncrypt3();

        int len = existing_password.getEncrypt3().length();

        int n=len-1;
        for(int i=0;i<(len/2);i++){
            swap(res[i],res[n]);
            n = n-1;
        }

        existing_password.setEncryptedPassword(res);

        string encryptinput = existing_password.getEncryptedPassword(); 

        cout << encryptinput << endl;

        if (encryptinput == adminpassword && existing_user.username == adminuser){
            Admin rootuser;
            cout << "Admin Menu:" << endl;
            cout << "1. Make a system announcement: " << endl;
            cout << "Please enter the announcement: " << endl;
            cin >> rootuser.admininput;
            rootuser.adminannou1.open("adminannouncement.txt");
            rootuser.adminannou1 << rootuser.admininput << "\n"<< endl;
            rootuser.adminannou1.close();
            return 0;
        }

    }
    if (user_input == 2) {
        User new_account;
        cout << "Type in account type: Student or Lecturer: " << endl;
        cin >> new_account.account_type;
        if (new_account.account_type == stu_type){
            Student new_student;
            cout << "Please enter a new username: " << endl;
            cin >> new_account.username;
            cout << "Please enter a new password: " << endl;
            cin >> password_input;
            new_student.setstudentpassword(password_input);
            cout << "Please confirm your password:"  << endl;
            cin >> password_confirmation;
            
            while (password_confirmation != new_student.getstudentpassword()){
                cout << "Please try again: " << endl;
                cin >> password_input;
                new_student.setstudentpassword(password_input);
                cout << "Please confirm your password:"  << endl;
                cin >> password_confirmation;
            }

        } 
        if (new_account.account_type == stu_type){
            Student new_student;
            cout << "Please enter a new username: " << endl;
            cin >> new_account.username;
            cout << "Please enter a new password: " << endl;
            cin >> password_input;
            new_student.setstudentpassword(password_input);
            cout << "Please confirm your password:"  << endl;
            cin >> password_confirmation;
            while (password_confirmation != new_student.getstudentpassword()){
                cout << "Please try again: " << endl;
                cin >> password_input;
                new_student.setstudentpassword(password_input);
                cout << "Please confirm your password:"  << endl;
                cin >> password_confirmation;
            }
            new_password.setPlainPassword(password_input);
            new_password.setEncrypt1(new_password.getPlainPassword());

            string message = new_password.getEncrypt1();
            int shift = 13;

            new_password.setEncrypt2(encrypt(message, shift));
            new_password.setEncrypt3(curr_time.clock_day + curr_time.clock_month + curr_time.clock_year + curr_time.clock_hour + curr_time.clock_min + curr_time.clock_sec + new_password.getEncrypt2());
            
            string res1 = new_password.getEncrypt3();
            
            int len1 = res1.length();
            int n1=len1-1;
            for(int i=0;i<(len1/2);i++){
                swap(res1[i],res1[n1]);
                n1 = n1-1;
            }
        }
    }

};

