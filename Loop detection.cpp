#include<bits/stdc++.h>
using namespace std;
int loop_detection(int i,int visited[],vector<int>adj[])
{
    if(visited[i]==0)
        visited[i]=1;
    for(int j = 0; j < adj[i].size(); j++)
    {
        int v = adj[i][j];
        if(visited[v] == 0)
            loop_detection(v,visited,adj);
        else
            return 1;
    }

    visited[i]=0;
}
int main()
{
    int n,e,u,v,f=0;
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
    for(int i=0; i<n; i++)
    {
        f=loop_detection(i,visited,adj);
        if(f==1)
        {
            cout<<endl<<"Loop is detected"<<endl;
            break;
        }
    }
    if(f!=1)
        cout<<endl<<"There is no loop"<<endl;
}