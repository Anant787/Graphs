//Cycle detection by BFS

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkforcycle(int s,int V,vector<int>adj[],vector<int>&vis)
{
    queue<pair<int,int>> q;
    
    vis[s]=true;
    q.push({s,-1});
    
    while(!q.empty())
    {
        int node=q.front().first;
        int pre=q.front().second;
        q.pop();
        
        /*
        int ch=node;
        cout<<ch<<" ";
        */
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                vis[it]=true;
                q.push({it,node});
            }
            else if(pre!=it)
                {
                    return true;
                }
        }
    }
    
    return false;
    
}

bool iscycle(int V,vector<int> adj[])      
{
    vector<int> vis(V+1,0);         
    
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])              
        {
            if(checkforcycle(i,V,adj,vis))
            {
                return true;
            }
        }
    }
    
    return false;     
}


int main()
{
    int V,E;
    cout<<"Enter the nodes and Edges :: ";
    cin>>V>>E;
    
    vector<int> adj[V+1] ;     
    cout<<"Input the edges of graph :: "<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);        
        adj[v].push_back(u);
    }
    
    if(iscycle(V,adj))
        cout<<"cycle is detected";
    else
        cout<<"Cycle is not detected";
    return 0;
}

