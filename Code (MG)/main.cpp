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
        string admin_username[i] = {"admin"};
        string admin_password[i] = {"MMMMMMMYMMAMZQN2350053112024081"};
    
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
        void setEncrypt1(string en1){
            encrypt1 = en1;
        }
        string getEncrypt1(){
            return encrypt1;
        }
        void setEncrypt2(string en2){
            encrypt2 = en2;
        }
        string getEncrypt2(){
            return encrypt2;
        }
        void setEncrypt3(string en3) {
            encrypt3 = en3;
        }
        string getEncrypt3(){
            return encrypt3;
        }
        void setDecrypt1(string de1){
            decryption1 = de1;
        }
        string getDecrypt1(){
            return decryption1;
        }
        void setDecrypt2(string de2){
            decryption2 = de2;
        }
        string getDecrypt2(){
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
int main () {
    int user_input;
    cout << "1. Log in or 2. Create Account: " << endl;
    cin >> user_input;
    while (user_input > 2) {
        cout << "Please pick 1 or 2: " << endl;
        cin >> user_input;
    }
    if (user_input = 1){
        User new_account;
        cout << "Type in account type: Student, Admin or Lecturer: " << endl;
        cin >> new_account.account_type;
        

        
    }
    
}
