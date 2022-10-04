// CSCI 1300 Fall 2022
// Author: Alejandro Chumil
// Recitation: 304 – Nikhith Sannidhi
// Project 1 - Problem # 6

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

double bestSimilarity(string inputTune, string targetTune)
{
    if(inputTune.length() < targetTune.length())
    {
        return 0;
    }
    
    double score = -100;
    double maxScore = -100;
    for(int i = 0; i < inputTune.length() - targetTune.length() + 1; i+=2)
    {
        /*this score variable will utilize tuneSimilarity function by passing in
        the input string along with target string. */

        double score = tuneSimilarity(inputTune.substr(i,targetTune.length()),targetTune);

        //this simply compares if score is greater than previous score
        if(score > maxScore)
        {
            //stores the max score in maxScore variable
            maxScore = score;
            
        }
    }
    return maxScore;
}

void printTuneRankings(string str1, string str2, string str3, string targetInput)
{
    double string1 = bestSimilarity(str1,targetInput);
    double string2 = bestSimilarity(str2,targetInput);
    double string3 = bestSimilarity(str3,targetInput);

    if(string1 == string2 && string2 == string3) // if all three are equal to each other
    {
        cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
    }
    if(string1 == string3 && string1 > string2)
    {
        cout << "1) Tune 1, 2) Tune 3, 3) Tune 2" << endl;
    }
    if(string2 > string1 && string2 > string3 && string1 == string2) 
    {
        cout << "1) Tune 2, 2) Tune 1, 3) Tune 3" << endl;
    }
    if(string1 > string2 && string2 > string3) // 1 2 3
    {
        cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
    }
    if(string1 > string3 && string3 > string2)
    {
        cout << "1) Tune 1, 2) Tune 3, 3) Tune 2" << endl;
    }
    if(string2 > string1 && string2 > string3 && string1 > string3)// when 2 is greater than 1 and 1 is greater than 3
    {
        cout << "1) Tune 2, 2) Tune 1, 3) Tune 3" << endl;
    }
    if(string3 > string2 && string2 > string1) // when 3 is greater than 2 and when 2 is greater than 1
    {
        cout << "1) Tune 3, 2) Tune 2, 3) Tune 1" << endl;
    }
    if(string2 > string3 && string3 > string1) // when 2 is greater than 3 and 3 greater than 1
    {
        cout << "1) Tune 2, 2) Tune 3, 3) Tune 1" << endl;
    }
    
    return;

}

int main()
{
    string str1 = "D3D4";
    string str2 = "E3D4";
    string str3 = "D3F4";
    string targetInput = "A7";
    printTuneRankings(str1,str2,str3,targetInput);

    return 0;



}