#include <iostream>
#include<bits/stdc++.h>

using namespace std;

map <char,int> dict1;

map <int,char> dict2;

void create_dict()
{

	for(int i = 1; i < 27; i++)
		dict1[char(64 + i)] = i;

	dict2[0] = 'Z';

	for (int i = 1; i < 26; i++)
		dict2[i] = char(64 + i);

	return;
}

string encrypt(string message, int shift)
{
	string cipher = "";
	for(int  i = 0; i < message.size(); i++)
	{
		if(message[i] != ' ')
		{
			int num = (dict1[message[i]] + shift) % 26;

			cipher += dict2[num];
		}
		else
		{
			cipher += " ";
		}
	}
	return cipher;
}

string decrypt(string message, int shift)
{
	string decipher = "";
	for(int i = 0; i < message.size(); i++)
	{
		if (message[i] != ' ')
		{
			int num = (dict )
		}
	}
}