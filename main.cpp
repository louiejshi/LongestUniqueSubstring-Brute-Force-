//
//  main.cpp
//  LongestUniqueSubstring(Brute Force)
//
//  Created by Louie Shi on 8/6/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Result
{
public:
    string word;
    int length;
    
    Result()
    {
        word = "";
        length = 0;
    }
    
    Result(string str, int len)
    {
        word = str;
        length = len;
    }
};

bool isUnique(string str)
{
    set<char> mySet;
    set<char>::iterator itr;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(mySet.find(str[i]) == mySet.end())
        {
            mySet.insert(str[i]);
        }
        else
        {
            return false;
        }
    }
    return true;
}

Result lengthOfLongestSubstring(string s)
{
    Result res;
    string subs;
    int length = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = i; j < s.length(); j++)
        {
            length = j - i + 1;
            subs = s.substr(i, length);
            
            if(isUnique(subs) && (subs.length() > res.length))
            {
                res.word = subs;
                res.length = subs.length();
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[])
{
    string str1 = "bbbbb";
    
    Result res = lengthOfLongestSubstring(str1);
    
    cout << "Word: " << res.word << endl;
    cout << "Length: " << res.length << endl;
    
    return 0;
}
