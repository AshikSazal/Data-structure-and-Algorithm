#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int visited[],vector<int>adj[])
{
    if(visited[i] != 0)
        return;

    visited[i]=1;
    for(int j = 0; j < adj[i].size(); j++)
    {
        int v = adj[i][j];
        if(visited[v] == 0)
            dfs(v,visited,adj);
    }
    cout <<i<<" ";
}
int main()
{
    int n,e,u,v,s;
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

    for(int i=0; i<=n; i++)
    {

        if(visited[i]==0)
        {cout<<"connected components : ";
            dfs(i,visited,adj);
            cout<<endl;
        }
    }

}