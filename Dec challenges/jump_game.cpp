// 55. Jump Game
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.
// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.


//Very unique approach great question

//TC - O(N)
//SC - O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n=nums.size();
        int minj=0; //Let's say u reached last index so minj=0
        for(int i=n-2;i>=0;i--) //Start iterating from second last index till 0th index
        {
            minj++; //Forward indexes u check, if u rech there by incrementing 1 then u will definately reach the last index.
            if(nums[i]>=minj) //If you can cross this min jump value you will definately reach the last index.
            {
                minj=0; //Make it 0 as for this index u have checked
            }
        }
        return minj==0; //If it still remains 0 then u can reach the last index otherwise not.
    }
};
