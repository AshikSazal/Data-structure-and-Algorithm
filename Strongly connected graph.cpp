#include<bits/stdc++.h>
using namespace std;
int dfs(int i,int visited[],vector<int>adj[])
{
    static int c=0;
    if(visited[i] != 0)
        return c;

    visited[i]=1;
    for(int j = 0; j < adj[i].size(); j++)
    {
        int v = adj[i][j];
        if(visited[v] == 0)
            dfs(v,visited,adj);
    }
    c++;
}
int main()
{
    int n,e,u,v,s,z;
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>e;
    vector<int>adj[n];
    int visited[n];
    for(int i=0; i<n; i++)
        visited[i]=0;
    for(int i=0; i<e; i++)
    {
        cout<<"Edge "<<i<<" : ";
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    z=dfs(0,visited,adj);
    if(z==n)
        cout<<"Graph is strongly connected";
    else
        cout<<"Graph is not strongly connected";

}