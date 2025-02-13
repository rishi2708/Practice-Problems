// A C++ solution for longest palindrome substring.

// Problem Statement :- Given a string, find the longest substring which is a palindrome. 

/*
   Input: Given string :”forgeeksskeegfor”, 
   Output: Longest palindrome substring is: geeksskeeg and length is: 10 

   Input: Given string :”Geeks”, 
   Output: Longest palindrome substring is: ee and length is: 2
   
*/



#include <bits/stdc++.h>
using namespace std;

// Function to print a substring str[low..high]
void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

// This function prints the
// longest palindrome substring
// It also returns the length
// of the longest palindrome
int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();

    // All substrings of length 1
    // are palindromes
    int maxLength = 1, start = 0;

    // Nested loop to mark start and end index
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            int flag = 1;

            // Check palindrome
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;

            // Palindrome
            if (flag && (j - i + 1) > maxLength)
            {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
    cout << " and length is ";
    // return length of LPS
    return maxLength;
}

// Driver Code
int main()
{
    string str = "forgeeksskeegfor"; // Sample Input
    cout << longestPalSubstr(str);
    // Output :- Longest palindrome substring is: geeksskeeg and length is: 10 

    return 0;
}
