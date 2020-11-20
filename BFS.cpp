#include<bits/stdc++.h>
using namespace std;
void bfs(int s,int n,vector<int>adj[],int visited[])
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        cout << u << " ";

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(visited[v] == 0)
            {
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
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

    cout<<"Source node : ";
    cin>>s;

    bfs(s,n,adj,visited);

}