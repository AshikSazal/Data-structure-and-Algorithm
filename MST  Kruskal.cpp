#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int p,r;
};
struct Edge
{
    int u,v,w;
};
bool compare(struct Edge x,struct Edge y)
{
    return x.w<y.w;
}
void makeset(struct Node node[],int x)
{
    node[x].p=x;
    node[x].r=0;
}
int findset(struct Node node[],int x)
{
    if(node[x].p!=x)
        node[x].p=findset(node,node[x].p);
    return node[x].p;
}
void setunion(struct Node node[],int x,int y)
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
int kruskal(struct Node node[],struct Edge edge[],vector<int>&selectedEdge,int n,int e)
{
    int mstWeight=0;
    for(int i=0; i<n; i++)
        makeset(node,i);
    sort(edge,edge+e,compare);
    for(int i=0; i<e; i++)
    {
        int x=edge[i].u;
        int y=edge[i].v;
        int x_parent=findset(node,node[x].p);
        int y_parent=findset(node,node[y].p);
        if(x_parent!=y_parent)
        {
            setunion(node,x_parent,y_parent);
            selectedEdge.push_back(i);
            mstWeight+=edge[i].w;
        }
    }
    return mstWeight;
}
int main()
{
    int n,e,u,v,w;
    cout<<"Enter the number of vertex and edge : ";
    cin>>n>>e;
    struct Node node[n];
    struct Edge edge[e];
    vector<int>selectedEdge;
    for(int i=0; i<e; i++)
    {
        cout<<"Edges and weight : ";
        cin>>u>>v>>w;
        edge[i].u=u;
        edge[i].v=v;
        edge[i].w=w;
    }
    cout<<"Total Weight : "<<kruskal(node,edge,selectedEdge,n,e);
    cout<<"\nSelected edges are\n";
    for(int i=0; i<selectedEdge.size(); i++)
    {
        int x=selectedEdge[i];
        cout<<edge[x].u<<"-"<<edge[x].v<<endl;
    }
}