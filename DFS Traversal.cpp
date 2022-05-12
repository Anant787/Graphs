/*
 -Depth-First-Search(DFs)
 
 -Depth-first search is an algorithm for traversing 
  or searching tree or graph data structures.
  
  
  Algorithm: 
  1-Create a recursive function that takes the index of the node and a visited array.

  2-Mark the current node as visited and print the node.
    Traverse all the adjacent and unmarked nodes and 
    call the recursive function with the index of the adjacent node.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&storeDfs)
{
    storeDfs.push_back(node);    // store the node which is inseretd
    vis[node]=1;                 //marks as visited
    
    int ch=node;
    cout<<ch<<" "; 
    
    for(auto it : adj[node])      //Traverse for every adjcency node
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,storeDfs);     //once this recursive is over then it goes up and occur recursion
        }
    }
    
}

vector<int>dfsOfGraph(int n,vector<int> adj[])   //n= no. of nodes and adj = adjcency list
{
    vector<int> storeDfs;            //store the dfs traversal
    vector<int> vis(n+1,0);         // create a visite array for visiting element of size (NODE+1)
    
    for(int i=1;i<n;i++)
    {
        if(!vis[i])             //check for unvisited 
        {
            dfs(i,vis,adj,storeDfs);         
        }
    }
    return storeDfs;
}


int main()
{
    int n,m;
    cout<<"Enter the node and edges :: ";
    cin>>n>>m;
    
    vector<int> adj[n+1];      
    cout<<"Input the edges ::"<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);        
        adj[v].push_back(u);
    }
    
    dfsOfGraph(n,adj);    //n= node and adj is adjcency list
    return 0;
}
