/*
Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

*/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<char> myvec;
        int longestLength = 0;
        for(int i = 0; i < s.length(); i++)
        {
            auto it = std::find(myvec.begin(), myvec.end(), s[i]);
            if(it != myvec.end())
            {
                if(longestLength < myvec.size())
                    longestLength = myvec.size();
                it++;
                myvec.erase(myvec.begin(), it);
            }

            myvec.push_back(s[i]);
        }

if(longestLength < myvec.size())
    longestLength = myvec.size();

return longestLength;
    }
};
