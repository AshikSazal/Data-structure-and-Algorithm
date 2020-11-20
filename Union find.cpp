#include<bits/stdc++.h>
using namespace std;
struct Node{
    int p,r;
};
void makeset(struct Node node[],int x)
{
    node[x].p=x;
    node[x].r=0;
}
void link(struct Node node[],int x,int y)
{
    if(node[x].r>node[y].r)
        node[y].p=x;
    else
    {
        node[x].p=y;
        if(node[x].r==node[y].r)
            node[y].r++;
    }
}
int findset(struct Node node[],int x)
{
    if(node[x].p!=x)
        node[x].p=findset(node,node[x].p);
    return node[x].p;
}
void setunion(struct Node node[],int x,int y)
{
    int x_parent=findset(node,x);
    int y_parent=findset(node,y);
    link(node,x_parent,y_parent);
}
int main()
{
    int u,v,n,e;
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>e;
    struct Node node[n];
    for(int i=0;i<n;i++)
        makeset(node,i);

    for(int i=0;i<e;i++)
    {
        cout<<"Edges : ";
        cin>>u>>v;
        setunion(node,u,v);
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Vertex "<<i<<endl;
        cout<<"Parent : "<<node[i].p<<endl;
        cout<<"Rank : "<<node[i].r<<endl;
        cout<<endl;
    }
}