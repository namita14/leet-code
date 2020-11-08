/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

*/
#include<iostream>
#include<map>
#include<vector>

class Solution {
public:
		std::vector<int> twoSum(std::vector<int>& nums, int target) {
        unordered_map<int,int> m1;
        std::vector<int> p1;
        for(int i=0; i<nums.size(); i++)
        {
            if(m1.find(target-nums[i])!=m1.end())
            {
                
                p1.push_back(m1[target-nums[i]]);
                p1.push_back(i);
                return p1;
            }
            
            else
            {
                m1[nums[i]]=i;
            }
        }
        return p1;
    }
};
