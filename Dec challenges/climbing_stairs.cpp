// 70. Climbing Stairs

// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

//Application of dp+recursion
//We have used Memoization technique of dp here so very imp ques

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cnt(int n,int stp,vector<int>&dp)
    {
        if(stp==n) //Base condition when step is equal to n then found 1 way add 1
        {
            return 1;
        }
        if(stp>n) //When step is greater than n then return 0
        {
            return 0;
        }
        if(dp[stp]!= -1) //Checking if at that particular step that value is already calculated then no need to calculate and return 0 again because let's say if stp>n in right recursion tree at step 5 so it may be possible that stp>n in left recursion tree also at some value of step, so to avoid this repetted evaluation of that step where stp>n, we have to apply memoization technique in dp.
        {
            return dp[stp];
        }
        dp[stp]=cnt(n,stp+1,dp) + cnt(n,stp+2,dp); //If not -1 calculating 1st time
        return dp[stp];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1); //Creating extra space 
        int step=0;
        return cnt(n,step,dp);
    }
};











