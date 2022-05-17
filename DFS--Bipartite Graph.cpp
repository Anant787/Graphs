/*
  Bipartite Graph by DFS

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node,vector<int>adj[],int color[])
{
    if(color[node]==-1)
    {
        color[node]=1;
    }
    
    for(auto it : adj[node])
    {
        if(color[it]==-1)
        {
            color[it]= 1 - color[node]; 
            
            if(!bipartiteDfs(it,adj,color))
            {
                return false;
            }
        }
        else if(color[it]==color[node])
        {
            return false;
        }
    }
    return true;
}

bool checkbipartite(vector<int> adj[],int V)
{
    int color[V];
    memset(color,-1,sizeof color);
    
    for(int i=1;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartiteDfs(i,adj,color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int V,E;
    cout<<"Enter the vertex and edges :: ";
    cin>>V>>E;
    
    vector<int>adj[V];
    cout<<"Insert the edges ::"<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(checkbipartite(adj,V))
    {
        cout<<"Graph is Bipartite..";
    }
    else
    {
        cout<<"Graph is not Bipartite";
    }
    return 0;
}
