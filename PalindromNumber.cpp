/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Follow up: Could you solve it without converting the integer to a string?

 

Example 1:

Input: x = 121
Output: true
*/

#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        int xx = x;
        if (x < 0) return false;
        
        long long ret = 0;
        while (x >= 10) {
            ret = ret*10 + x%10;
            x /= 10;
        }
        ret = ret * 10 + x;
        
        return ret == xx;
        
    }
};
