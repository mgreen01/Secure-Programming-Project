#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main () {
    ifstream inputFile;
    string user_name;
    int user_age;
    int user_type;
    string user_password;

    cout << "Enter your username: " << endl;
    cin >> user_name;
    string user_name2 = user_name +".txt";
    cout << user_name2 << endl;

    inputFile.open(user_name2);

    if (inputFile){
        inputFile >> user_type;
        inputFile >> user_age;
        inputFile >> user_password;
        inputFile.close();
        cout << user_type << endl;
        cout << user_age << endl;
        cout << user_password << endl;
    }

    



}