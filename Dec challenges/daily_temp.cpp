// 739. Daily Temperatures

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

//TC - O(N)
//SC - O(N)

//For understanding see notebook

#include<bits/stdc++.h>
using namespace std;
//I have done this with brute force without using stack, this is the standard question of stack.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s1;
        int n=temperatures.size();
        vector<int>ans(n); //Taken vector of same size as temp.
        for(int i=0; i<n; i++)
        {
            while(s1.size()>0 && temperatures[i]>temperatures[s1.top()]) // This is the main cond if stack is not empty then check whether at top index value is lesser than current i value if this is true then at the same top index of stack insert the count which is i-s1.top() the pop that.
            {
                ans[s1.top()]=i-s1.top();
                s1.pop();
            }
            s1.push(i);// If next value is smaller then simply insert that value
        }
        return ans;

        
    }
};