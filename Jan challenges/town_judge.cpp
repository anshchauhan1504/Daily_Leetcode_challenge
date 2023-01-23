// 997. Find the Town Judge
// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

// Example 1:

// Input: n = 2, trust = [[1,2]]
// Output: 2


//TC - O(N)
//SC - O(N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> vec(n+1,{0,0});
        for(int i=0;i<trust.size();i++)
        {
            vec[trust[i][0]].first+=1; //People trust->calculating for left side
            vec[trust[i][1]].second+=1; //People trust->calculating for right side
        }
        for(int i=1;i<=n;i++)
        {
            if(vec[i].first==0 && vec[i].second==n-1) //Condition for town judge
            {
                return i;
            }
        }
        return -1;     
    }
};
