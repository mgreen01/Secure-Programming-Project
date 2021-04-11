//This is a blank file
#include <iostream>
using namespace std;

int length = 0;

class Crypto {
    string plain_password;
    string encrypted_password;
};

class User {
    public:
    string username;
    int age;
    int account_type;
    string password;
};

int main () {
    cout << "Please enter a new username: " << endl;
    User new_user;
    cin >> new_user.username;
    cout << "Please enter your age: " << endl;
    cin >> new_user.age;
    cout << "Please enter a new password: " << endl;
    cin >> new_user.password;

    for (int i= 0; new_user.password[i] !='\0'; i++) {
        length++;
    }
    
    cout << length << endl;
    return 0;
    
};