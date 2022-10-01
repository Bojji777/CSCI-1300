// CSCI 1300 Fall 2022
// Author: Alejandro Chumil
// Recitation: 304 – Nikhith Sannidhi
// Project 1 - Problem # 3

#include <iostream> 
#include <string>
#include <cassert>

using namespace std;

bool isValidNote(string s)
{        
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

int numValidNotes(string s)
{
    int count = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(isValidNote(s.substr(i,2)))//comparing element 1 to 2, 2 to 3, 3 to 4, 4 to 5....etc 
        {
            count++;//how many times it was a valid SPN note
        }
    }
    return count;
}

int main()
{
    string str = "Hello";
    cout << "Enter string" << endl;
    getline(cin,str);

    
    cout << numValidNotes(str) << endl;
}