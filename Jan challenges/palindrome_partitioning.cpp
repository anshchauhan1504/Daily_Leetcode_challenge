// 131. Palindrome Partitioning
// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

//TC - o(N^2logn)
//SC - o(N)
class Solution {
public:
   
   bool isPalindrome(string S){ //Checking whether the substring is palindrome
     string h = S;
     reverse(h.begin(),h.end());
     if(h==S){
         return true;
     }
     else{
         return false;
     }
      
    }

    void solve(vector<vector<string>>&ans, vector<string>&temp,string s)
    {
        if(s.size()==0) //Base case return involves backtracking
        {
            ans.push_back(temp);
            return; 
        }
        for(int i=0;i<s.size();i++) //Iterate over each char then make substring and check each whether palindrome or not. If yes the add into temp and when reached based condition then it will be added into ans.
        {
            string a=s.substr(0,i+1);
            if(isPalindrome(a))
            {
                temp.push_back(a);
                solve(ans,temp,s.substr(i+1)); //Recursive call
                temp.pop_back(); //Backtracking
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
     vector<vector<string>>ans;
     vector<string>temp;
     solve(ans,temp,s);
     return ans;    
    }
};
