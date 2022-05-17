/*
 # Bipartite Graph are the Graph that can be colored using 2 color 
  whose such that adjacent node have same color.
  
 # any graph have the ODD length cycle in not Bipartite graph.
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bipartitebfs(int src,vector<int> adj[],int color[])
{
    queue<int> q;
    q.push(src);
    color[src]=1;
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(auto it : adj[node])
        {
            if(color[it]==-1)
            {
                color[it]= 1-color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkbipartite(vector<int> adj[],int V)
{
    int color[V];
    memset(color,-1,sizeof color);
    
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartitebfs(i,adj,color))
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
    
    vector<int> adj[V];
    
    cout<<"Insert the edges "<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if(checkbipartite(adj,V))
        cout<<"Graph is Bipartite..";
    else
        cout<<"Graph is not Bipartite..";
        
    return 0;    
}
