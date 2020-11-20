#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,m,u,v;
    cout<<"Plz enter the number of nodes : ";
    cin>>n;
    cout<<"Plz enter the edges : ";
    cin>>m;
    vector<int>node[n];
    for(i=0;i<m;i++)
    {
        cout<<"Edge "<<i<<" : ";
        cin>>u>>v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    for(i=0;i<n;i++)
    {
        cout<<"Adjacent of node "<<i<<" : ";
        for(int j=0;j<node[i].size();j++)
            cout<<node[i][j]<<" ";
        cout<<endl;
    }
}