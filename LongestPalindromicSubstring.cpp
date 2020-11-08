#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2)
        {
            return s;
        }

    int i = 0;
    int start = 0, max = 1;
    int l_ptr = 0, r_ptr = 0;
    for(i = 0; i < len;)
    {
        l_ptr = i;
        r_ptr = i;
        while (r_ptr < len && s[l_ptr] == s[r_ptr])
        {
            ++r_ptr;
        }
        i = r_ptr;
        --l_ptr;
        
        while(l_ptr > -1 && r_ptr < len && s[l_ptr] == s[r_ptr])
        {
            --l_ptr;
            ++r_ptr;
        }
        
        if (r_ptr-l_ptr-1 > max)
        {
            start = l_ptr+1;
            max = r_ptr-l_ptr-1;
        }
    }
    
    return s.substr(start, max);
        
    }
};
