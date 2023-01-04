// 2244. Minimum Rounds to Complete All Tasks
// You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

// Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

// Example 1:

// Input: tasks = [2,2,3,3,2,4,4,4,4,4]
// Output: 4
// Explanation: To complete all the tasks, a possible plan is:
// - In the first round, you complete 3 tasks of difficulty level 2. 
// - In the second round, you complete 2 tasks of difficulty level 3. 
// - In the third round, you complete 3 tasks of difficulty level 4. 
// - In the fourth round, you complete 2 tasks of difficulty level 4.  
// It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
        }
        int com=0;
        for(auto x:mp)
        {
            if(x.second<=1)
            {
                return -1;
            }
            else if(x.second==2)
            {
                com+=1;
            }
            else{
                com+=ceil((double)x.second/3.0);
            }
        }
        return com;
        
    }
};