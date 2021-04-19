//This is a blank file
#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
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

class User {
    public:
    string username;
    string age;
    string account_type;
    string password;
};

//contains the necessary variables and the functions for the cryptography process
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

    string decrypt(string message, int shift)
    {
        string passdecip = "";
        for(int i = 0; i < message.size(); i++)
        {
            if(message[i] != ' ')
            {
                int num =(dict1[message[i]] - shift + 26) % 26;

                passdecip += dict2[num];
            }
            else
            {
                passdecip += " ";
            }
        }
        return passdecip;
    }
int main () {
    //user input
    new_password.create_dict();
    cout << "Please enter a new username: " << endl;
    User new_user;
    cin >> new_user.username;
    cout << "Please enter your age: " << endl;
    cin >> new_user.age;
    cout << "Please enter a new password: " << endl;
    cin >> new_user.password;
    //Time formatting
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


   //encryption process
    new_password.setPlainPassword(new_user.password);
    new_password.setEncrypt1(new_password.getPlainPassword());

    string message = new_password.getEncrypt1();
    int shift = 13;

    new_password.setEncrypt2(encrypt(message, shift));

    cout << new_password.getEncrypt2()<< endl;

    new_password.setEncrypt3(curr_time.clock_month + curr_time.clock_year + new_user.age + new_password.getEncrypt2());

    cout <<"Encryption Part 3: " << new_password.getEncrypt3() << endl;

    string res = new_password.getEncrypt3();

    int len = new_password.getEncrypt3().length();

    int n=len-1;
    for(int i=0;i<(len/2);i++){
        swap(res[i],res[n]);
        n = n-1;
    }

    cout << res << endl;

    new_password.setEncryptedPassword(res);

    cout << "Encrypted Password: "<< new_password.getEncryptedPassword() << endl;

    string res1 = new_password.getEncryptedPassword();

    int len1 = res1.length();
    int n1=len1-1;
    for(int i=0;i<(len1/2);i++){
        swap(res1[i],res1[n1]);
        n1 = n1-1;
    }

    new_password.setDecrypt1(res1.substr(16));

    cout << "Decryption Part 1: " << res1 << endl;
    cout << "Decryption Part 2: " << new_password.getDecrypt1() << endl;

    new_password.setDecrypt2(encrypt(new_password.getDecrypt1(), shift));

    cout << "Decrypted Password: "<< new_password.getDecrypt2() << endl;





};


