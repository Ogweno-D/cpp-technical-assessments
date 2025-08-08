//
// Created by OG on 08/08/2025.
//

#include <iostream>
#include <string.h>
#include<string>
#include <vector>
using namespace std;
// Get the longest String
// 1. Validate each string
// 2. Check if they are the longest in the array.


bool isValid(const vector<string> &arr, const char validChars[]);
string getLongestString(const vector<string> &arr,const char validChars[]);

int main()
{
    // SHORT WAY TESTING
    vector<std::string> my_arr = {"apple", "banana", "kiwi", "orange"};
    const char valid_chars[] = "abcdefghijklmnopqrstuvwxyz";

    // Example 1: With valid strings
    cout << "The longest string is: " << getLongestString(my_arr, valid_chars) << std::endl;

    // Example 2: With an invalid string (contains a digit '1')
    vector<std::string> invalid_arr = {"apple", "banana", "kiwi1", "orange"};
    cout << "The longest string with an invalid array is: " << getLongestString(invalid_arr, valid_chars) << std::endl;



    /// IGNORE IF POSSIBLE OR USE IT TO GAIN A DEEPER UNDERSTANDING!
    /// OF EVEN OPTIMIZE IT!
    // int max_capacity = 20;
    // string str = " ";
    // auto* arr = new vector<string>;
    // auto* validChars = new char[max_capacity];
    // int length =0;
    // char choice =' ';
    //
    //
    // do{
    //    cout << " Enter your valid characters ( up to :" <<max_capacity-1<<")" << endl;
    //    cin.getline(validChars,max_capacity);
    //
    //    length = strlen(validChars);
    //
    //    if (length == 0)
    //    {
    //        cout << "Input cannot be empty, please try again." << endl;
    //    }
    //    else if (length >= max_capacity)
    //    {
    //        cout << "Input cannot be greater than " << max_capacity << " characters." << endl;
    //    }
    //
    // } while (length==0||length>=max_capacity);
    //
    // // cout << "Valid Character :" << endl;
    // // for (int i=0; i<length ; i++)
    // // {
    // //     cout << validChars[i] << ' ' << endl;
    // // }
    //
    // // Get the sentence
    // cout << "Enter valid strings for the sentence: " << endl;
    // // Loop for initial input of up to 10 strings
    // while (arr->size()<10)
    // {
    //     cout << "Enter string#" << arr->size()+1 <<" (or 'done' to finish)" <<endl;
    //     cin >> str;
    //
    //     if (str=="done")
    //     {
    //         break;
    //     }
    //     arr->push_back(str);
    // }
    //
    // // Room for more strings
    // if (arr->size() == 10)
    // {
    //     cout << "You have entered 10 strings. Do you wish to add more? ('y' or 'n')" << endl;
    //     cin >> choice;
    //
    //     if (choice =='y' || choice == 'Y')
    //     {
    //         cout << "Enter you next string (or 'done' to finish)" << endl;
    //
    //         while (true)
    //         {
    //             cout << "Enter string #" << arr->size()+1 << endl;
    //             cin >> str;
    //             if (str=="done")
    //             {
    //                 break;
    //             }
    //             arr->push_back(str);
    //         }
    //     }
    // }
    //
    // string lstring = getLongestString(*arr,validChars);
    // cout << " Thank you thus far!" << endl;
    // cout << " The longest string in this sentence is :" << lstring << endl;
    //
    //
    // // Delete the pointers when out of scope to avoid memory leak
    // // Assigning them to null is to not have dangling pointers.
    // delete validChars;
    // validChars = nullptr;
    // delete arr;
    // arr = nullptr;

}

// To check if a character exists in the valid set of characters
bool containsChar(const char validChars[], char c)
{
    for (int i =0; validChars[i]!='\0' ; i++)
    {
        if (validChars[i] == c)
        {
            return true;
        }
    }
    return false;
}

bool isValid(const vector<string> &arr, const char validChars[])
{
    // Check for null pointer on the valid chars
    if (validChars == nullptr)
    {
        return false;
    }


    // Check all the characters are from the valid set
    // For every string in the array
    for (string s : arr)
    {
        // For every character in the string s
        for (char c : s)
        {
            if (!containsChar(validChars, c))
            {
                return false;
            }
        }
    }

    return  true; // if all characters are valid!
}

string getLongestString(const vector<string> &arr, const char validChars[])
{
    string longestString = " ";

    if (isValid(arr, validChars))
    {
        int maxLength = 0;
        for (const string& s : arr)
        {
            if (s.length() > maxLength)
            {
                maxLength = s.length();
                longestString = s;
            }
        }
    }

    return longestString;
}
