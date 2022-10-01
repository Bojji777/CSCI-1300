// CSCI 1300 Fall 2022
// Author: Alejandro Chumil
// Recitation: 304 – Nikhith Sannidhi
// Project 1 - Problem # 4

#include <iostream>

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

double tuneSimilarity(string s1, string s2)
{
    if(s1.length() != s2.length())
    {
        return 0;
    }
    double numNotes = numValidNotes(s1);

    double count_1 = 0;
    double count_2 = 0;
    double count_3 = 0;

    double similarity = 0.0;
    for(int i = 0; i < s1.length(); i+=2)
    {
        if(s1.substr(i,1) != s2.substr(i,1) && s1.substr(i+1,1) == s2.substr(i+1,1))// seeing if we have same pitch different note
        {
            continue;
        }
        else if(s1.substr(i,2) == s2.substr(i,2))//if we have same note and same pitch
        {
            count_1++;
        }
        else if(s1.substr(i,1) == s2.substr(i,1) && (s1.substr(i+1,1) != s2.substr(i+1,1)))//if we have same note differnt pitch
        {
            count_2++; 
        }
        else if(s1.substr(i,1) != s2.substr(i,1) && (s1.substr(i+1,1) != s2.substr(i+1,1)))//differnt every
        {
            count_3++;
        }

        /* similarity = (number of matching notes / total number of notes) 
            + number of matching notes with matching pitches 
            - number of different notes with different pitches */
    }
    


    similarity = ((count_2 + count_1) /numNotes) + count_1 - count_3;
    return similarity;
}

int main()
{
    
    string s1 = "A2B3E2D1";
    string s2 = "A2D1F2D1";
    tuneSimilarity(s1,s2);
    
}