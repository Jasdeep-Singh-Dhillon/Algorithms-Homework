/*
 * Title: hw0_1.cpp
 * Abstract: This program reads the user's input data and 
 *           conducts sum and difference operations, depending 
 *           on the command key.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 07/25/2020
 */

#include <iostream>
#include <cmath>
using namespace std;

void addition(int num1, int num2);
void difference(int num1, int num2);

int main()
{
    int key, num1, num2;
    
    while(cin >> key && key != 9)
    {
        cin >> num1 >> num2;
        if(key == 1)
            addition(num1, num2);
        else if(key == 2)
            difference(num1, num2);
    }
    return 0;
}

void addition(int num1, int num2)
{
    cout << num1+num2 << endl;
}
void difference(int num1, int num2)
{
    cout << abs(num1-num2) << endl;
}