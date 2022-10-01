// CSCI 1300 Fall 2022
// Author: Alejandro Chumil
// Recitation: 304 – Nikhith Sannidhi
// Project 1 - Problem # 2

#include <iostream> 
#include <string>
#include <cassert>

using namespace std;

bool isValidNote(string s)
{        
     if(s.length() != 2) // checks length
        {
            return false;
        }    
        //validates first element of string
        if(s[0] == 'A' || s[0] == 'B' || s[0] == 'C' || s[0] == 'D' || s[0] == 'E' || s[0] == 'F'|| s[0] == 'G')
        {
            int num = 0;
            num = num * 10 + (s[1] - '0'); //converts char to int

            if(num >= 0 && num <=9)//validates number
            {
                return true;  
            }
        }  
        return false;   
}


bool isValidTune(string s)
{
    for(int i = 0; i < s.length(); i+=2) // iterates up by 2
    {
        if(!(isValidNote(s.substr(i,2)))//if the two elements that are inputted false return false 
        {
            return false;
        }
    }
    return true;
}


int main()
{
    string str = "";
    cout << "Enter string" << endl;
    getline(cin,str);

    assert(isValidTune(str) == true);




}