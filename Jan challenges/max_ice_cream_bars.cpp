// 1833. Maximum Ice Cream Bars
// It is a sweltering summer day, and a boy wants to buy some ice cream bars.

// At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

// Return the maximum number of ice cream bars the boy can buy with coins coins.

// Note: The boy can buy the ice cream bars in any order.

 

// Example 1:

// Input: costs = [1,3,2,4,1], coins = 7
// Output: 4
// Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int maxIceCream(vector<int>& costs, int coins) {
        // TC - O(Nlogn)
        // sort(costs.begin(),costs.end());
        // int c=0;
        // for(int i=0;i<costs.size();i++)
        // {
        //     if(costs[i]<=coins)
        //     {
        //         c+=1;
        //         coins-=costs[i];
        //     }
        // }
        // return c;
        //TC - O(N)
        vector<int>m(100001,0);
        for(int i=0;i<costs.size();i++)
        {
            m[costs[i]]++;
        }
        int count=0;
        int i=1; //Because min value of costs[i] = 1
        while(i<100001 && coins>=i)
        {
            if((long)m[i]*i>coins && coins>=i)
            {
                int bar=coins/i;
                count+=bar;
                coins-=i*bar;
                   break;
            }
            if(m[i]!=0 && coins>=0)
            {
                coins=coins-m[i]*i;
                count+=m[i];
            }
            i++;
        }
        return count;
    }   
    
};