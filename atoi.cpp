/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered a whitespace character.
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [-231,  231 - 1]. If the numerical value is out of the range of representable values, INT_MAX (231 - 1) or INT_MIN (-231) is returned.
 

Example 1:

Input: str = "42"
Output: 42
*/


#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
      int pointer(0);
      int result(0);
      int sign(0);
      
      // Discard white spaces
      while(str[pointer]==' '){
        ++pointer;
      }
      
      // Check for signs
      if(str[pointer]=='-'){
        sign = -1;
        ++pointer;
      }
      else if(str[pointer]=='+'){
        sign = 1; 
        ++pointer;
      }
      else if(isdigit(str[pointer])){
        sign = 1;        
      }
      else{
        return 0;
      }
      
      // Check for double signs...
      if(!isdigit(str[pointer])) return 0;
      
      // Convert the number found
      while(pointer < str.size() 
            && isdigit(str[pointer])){
        
        int digit = (int) str[pointer]-'0';
        
        // Check overflow for adding any number
        if(INT_MAX/10 >= result){ 
          result *= 10; 
        }
        else{
          return sign==-1 ? INT_MIN : INT_MAX;
        }
        
        // Check for overflow for at the unit level
        if(INT_MAX-digit >= result){
          result += digit;
        }
        else{
          return sign==-1 ? INT_MIN : INT_MAX;
        }
        
        ++pointer;
      }
      
      return sign*result;
    }
};
