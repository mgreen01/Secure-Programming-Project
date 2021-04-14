#include <iostream>

using namespace std;

void cipherEncryption(){
	cout << "Message can only be alphabetic" << endl;
	string message;
	cout << "Enter message: "
}
int main() 
{ 
	int choice;
	cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
	cin >> choice;
	cin.ignore();

	if(choice == 1){
		cout << endl << "---Encryption---" << endl;
		cipherEncryption(); 
	} else if (choice == 2){
		cout << endl << "---Decryption---" << endl;
	} else {
		cout << endl << "Wrong Choice" << endl;
	}

	return 0;
}