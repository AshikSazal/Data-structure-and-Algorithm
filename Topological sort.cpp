#include<bits/stdc++.h>
using namespace std;
void topological_sort(int i,int visited[],vector<int>adj[],stack<int>&st)
{
    if(visited[i] != 0)
        return;

    visited[i]=1;
    for(int j = 0; j < adj[i].size(); j++)
    {
        int v = adj[i][j];
        if(visited[v] == 0)
            topological_sort(v,visited,adj,st);
    }
    st.push(i);
}
int main()
{
    int n,e,u,v,s;
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>e;
    vector<int>adj[n];
    stack<int>st;
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
        if(visited[i]==0)
            topological_sort(i,visited,adj,st);

    while(st.empty()==0)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}