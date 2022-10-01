// CSCI 1300 Fall 2022
// Author: Alejandro Chumil
// Recitation: 304 – Nikhith Sannidhi
// Project 1 - Problem # 1

#include <iostream> 
#include <string>
#include <cassert>

using namespace std;

bool isValidNote(string s)
{        
    //B4
     if(s.length() != 2)
        {
            return false;
        }    
        if(s[0] == 'A' || s[0] == 'B' || s[0] == 'C' || s[0] == 'D' || s[0] == 'E' || s[0] == 'F'|| s[0] == 'G')
        {
            int num = 0;
            num = num * 10 + (s[1] - '0'); //converts char to int

            if(num >= 0 && num <=9)
            {
                return true;  
            }
        }  
        return false;   
}
int main()
{
    
    string str = " ";
    cout << "Enter SPN" << endl;
    getline(cin, str);

    assert(isValidNote(str) == true);

    
    
}


