//Cycle Detection BY DFS

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkforcycle(int node,int parent,vector<int> Adj[],vector<int> &vis)
{
    vis[node]=1;
    
    for(auto it : Adj[node])
    {
        if(vis[it]==0)
        {
            if(checkforcycle(it,node,Adj,vis))
                return true;
        }
        else if(it!=parent)
            return true;
    }
    return false;
}

bool iscycle(vector<int>Adj[],int V)
{
    vector<int>vis(V+1,0);
    
    for(int i=1;i<V;i++)
    {
        if(!vis[i])
        {
            if(checkforcycle(i,-1,Adj,vis))
                return true;
        }
    }
    return false;
}

int main()
{
    int V,E;
    cout<<"Enter the Vertexs and edges :: ";
    cin>>V>>E;
    
    vector<int>Adj[V];
    
    cout<<"Insert the edges ::"<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    
    if(iscycle(Adj,V))
        cout<<"Cycle is Detected..";
    else
        cout<<"Cycle is not present..";
    
    return 0;    
}
