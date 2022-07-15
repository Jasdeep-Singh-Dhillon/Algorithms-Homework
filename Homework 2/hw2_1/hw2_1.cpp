/*
 * Title: hw2_1.cpp
 * Abstract: This program reads input string and checks if they are anagram or not.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 09/08/2020
 */

#include <iostream>
using namespace std;

string sort(string str);
bool anagram(string str1, string str2);
void duplicate_count(string str);
int count(string str, char ch);

int main() 
{
  string str1;
  cin >> str1;

  string str2;
  cin >> str2;

  str1 = sort(str1);
  str2 = sort(str2);

  if(anagram(str1, str2))
  {
    cout << "ANAGRAM" << endl;
    duplicate_count(str1);
  }
  else
  {
    cout << "NO ANAGRAM";
  }
  return 0;
}

string sort(string str)
{
  for(int i=0; i<str.length(); i++)
  {
    for(int j=0; j<str.length(); j++)
    {
      if(str[i]<str[j])
      {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  return str;
}

bool anagram(string str1, string str2)
{
  if(str1.length() != str2.length())
  return false;

  for(int i=0; i<str1.length(); i++)
  {
    if(str1[i] != str2[i])
    {
      return false;
    }
  }
  return true;
}

void duplicate_count(string str)
{
  for(int i=0; i<str.length(); i++)
  {
    if(str[i]  != str[i+1])
    {
      cout << str[i] << ": " << count(str, str[i]) << endl;
    }
  }
}

int count(string str, char ch)
{
  int count = 0;
  for(int i=0; i<str.length(); i++)
  {
    if(str[i] == ch)
    count++;
  }
  return count;
}