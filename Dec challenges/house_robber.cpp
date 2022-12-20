// 198. House Robber

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

//This is the application of 0/1 Knapsack so practical application remember this how we approached it...detailed logic written in notebook.

// TC - O(N)
// SC -O(N)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[101]; //As the constraint is upto 100 that's why while in memoization we know that we have to take 1 size larger.
    int helper(int i,vector<int>& nums)
    {
        if(i>=nums.size()) //Base case - when index is out of vector range then return 0
        {
            return 0;
        }
        if(dp[i]!=-1) //If already that index has some value then no need to call again just return that same again.
        {
            return dp[i];
        }
        int take = helper(i+2,nums) + nums[i]; //If you are robbing first house then you can't rob next to it then rob i+2 and add the current house amount as you have robbed it.
        int not_take = helper(i+1,nums) + 0; //Here we are not robbing the first house so we can rob next to it and as we did not robbed 1st one so amount 0 added.
        dp[i] = max(take,not_take); //Using the memoization technique
        return dp[i];

    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp)); // It will copy -1 to each index of dp...TC - O(N) and SC - O(1)
        return helper(0,nums);
        
    }
};