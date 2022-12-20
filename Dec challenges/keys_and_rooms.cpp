// 841. Keys and Rooms
// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

// Example 1:

// Input: rooms = [[1],[2],[3],[]]
// Output: true
// Explanation: 
// We visit room 0 and pick up key 1.
// We then visit room 1 and pick up key 2.
// We then visit room 2 and pick up key 3.
// We then visit room 3.
// Since we were able to visit every room, we return true.

//Application of BFS traversal

//Explanation is there in notebook

//TC -O(N^2)
//SC -O(N)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size(); //Rooms size
        vector<bool>visited(n,false); //Made a visited vector to keep track which room is visited or which is not.
        queue<int>q; //We have used queue because we are checking first room then find key then second so it is happening in first in first out way.
        q.push(0); //Initially we have push 0 as it is always open
        visited[0]=true; //As we can visit 0 room any time
        while(q.empty()!=true) //Until queue is not empty
        {
            int r=q.front();  //Finding the room which is there in queue first
            q.pop();  //Pop out that
            
            for(auto key:rooms[r]) //Now time to find keys in that room 
            {
                if(visited[key]!=true) //If that key belongs to any room and that is already visited then will not do anything.
                {
                    visited[key]=true; //Not visited enetered in if and made it true
                    q.push(key); //Now push that key in queue so that with the help of which we can find the keys of other room after visiting that room.
                }

            }
        }
        for(auto x: visited) //Finally checking the visited vector if all are true then only true otherwise false.
        {
            if(x==false)
            {
                return false;
            }
        }
        return true;

        
    }
};