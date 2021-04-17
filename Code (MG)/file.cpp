#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class File {
    private:
        string userdatabase;
        string existing_username;
        string existing_password;
    public:
        void setexistingusername (string existuser){
            existing_username = existuser;
        }
        string getexistingusername () {
            return existing_username;
        } 
        void setexistingpassword (string existpass){
            existing_password = existpass;
        }
        string getexistingpassword () {
            return existing_password;
        }

        void setuserdatabase (string database){
            userdatabase = database;
        }
        string getuserdatabase () {
            return userdatabase;
        }
}

int main () {


}