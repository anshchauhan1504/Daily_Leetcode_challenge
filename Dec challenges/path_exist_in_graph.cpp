// 1971. Find if Path Exists in Graph

// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
// You want to determine if there is a valid path that exists from vertex source to vertex destination.
// Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

// Example 1:

// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2

//TC - O(V+E) V->Vertices E->edges
//SC - O(V+E)

//Explanation is there in notebook

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>&g,vector<int>&vis,int s, int d)
    {
        if(s==d) return true; // Checking if you reach to destination from source then return true
        if(vis[s]) return false; //If already visited then return false
        vis[s]=1; //Not visited then mark it visited
        for(int i=0;i<g[s].size();i++) // Open the connected node vector list of current node while traversing
        {
            if(dfs(g,vis,g[s][i],d)) return true; //If satisfy the base case it will return true
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++) //In this loop we are checking which node is connected to which node and storing in 2D vector.
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,0); //Making the visited vector
        return dfs(graph,visited,source,destination);
        
    }
};