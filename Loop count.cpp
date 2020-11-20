#include<bits/stdc++.h>
using namespace std;
int loop_count(int i,int visited[],vector<int>adj[])
{
    if(visited[i]==0)
        visited[i]=1;
    for(int j = 0; j < adj[i].size(); j++)
    {
        int v = adj[i][j];
        if(visited[v] == 0)
            loop_count(v,visited,adj);
        else
            return 1;
    }

    visited[i]=0;
}
int main()
{
    int n,e,u,v,f=0,c=0;
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>e;
    vector<int>adj[n];
    int visited[n],arr[n];
    for(int i=0; i<n; i++)
        visited[i]=0;
    for(int i=0; i<e; i++)
    {
        cout<<"Edge "<<i<<" : ";
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    for(int i=0; i<n; i++)
    {
        f=loop_count(i,visited,adj);
        if(f==1)
        {
            c=c+f;
        }
    }
    cout<<"loop is : "<<c<<endl;
}