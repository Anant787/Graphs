/*
  Breadth-First-Search(BFs)
  
  -It is travershing technique in which traversing
  the adjcent nodes first and after moved to next
  nodes.
  
  - Works on Queue.
  
  
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>bfsofgraph(int n,vector<int>adj[])      // n is no. of nodes
{
    vector<int> bfs;                         // vector bfs stored the traversal of nodes.
    vector<int> vis(n+1,0);         //create a visited array of size (NODES +1)and assigning to ZERO.
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])              //component for not visited element
        {
            queue<int> q;          //create a Queue
            q.push(i);            // Push elements in Queue
            vis[i]=1;             //Make visited array as 1 (for visted)
            
            while(!q.empty())           //iterate till queue is not empt
            {
                int node=q.front();      //took out the element form the Queue
                q.pop();                    // make sure it is deleted from the Queue
                bfs.push_back(node);        //here BFS is traverse the node
                
                int ch=node;
                cout<<ch<<" ";
                
                for(auto it: adj[node])  //all the adjcent node put into the Queue and easily accesible from adjacency node
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                        
                        
                    }
                }
            }
        }
    }
    
    return bfs;     
}


int main()
{
    int n,m;
    cout<<"Enter the nodes and Edges :: ";
    cin>>n>>m;
    
    vector<int> adj[n+1] ;     //Declare the adjacency matrix
    
    cout<<"Input the edges of graph :: "<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);        
        adj[v].push_back(u);
    }
    
    bfsofgraph(n,adj);             //n= nodes and adj= adjacency matrix
    return 0;
}
