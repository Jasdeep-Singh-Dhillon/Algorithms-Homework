/*
 * Title: hw9_3.cpp
 * Abstract: This program checks if an input string is a palindrome or not using recursion. 
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 11/12/2020
*/

#include<iostream>
#include<string>
using namespace std;

void lowerCase(string &str);
string removeInvalid(string str);
bool palindrome(string s, int begin, int end);

int main()
{
	string str;
	getline(cin, str);
	lowerCase(str);
	str = removeInvalid(str);
	if(palindrome(str, 0, str.length()-1))
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
}

void lowerCase(string &str)
{
	for(int i=0; i<str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
}

string removeInvalid(string str)
{
	string s="";
	for(int i=0; i<str.length(); i++)
	{
		if( (str[i]>'z' | str[i]<'a') & (str[i]<'0' | str[i]>'9') )
			continue;
		s+=str[i];
	}
	return s;
}

bool palindrome(string s, int begin, int end)
{
	if(s[begin]!=s[end])
		return false;
	if(begin-end<=1)
		return true;

	return true & palindrome(s, begin+1, end-1);
}