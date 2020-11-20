#include<bits/stdc++.h>
using namespace std;
class item
{
public:
    float v,w,r,x;
    int k;
    void setter(float vl,float wt)
    {
        v=vl,w=wt;
        r=v/w;
        x=0;
    }
};
bool comp(item a,item b)
{
    return a.r>b.r;
}
int main()
{
    int i,tw,n,f;
    float v,w;
    cout<<"How many number and total weight : ";
    cin>>n>>tw;
    item s[n];
    cout<<"Plz enter information in separate line (v,w)\n";
    for(i=0; i<n; i++)
    {
        cin>>v>>w;
        s[i].k=i;
        s[i].setter(v,w);
    }
    sort(s,s+n,comp);
    i=0,w=0;
    float a,profit=0;
    while(w<tw&&i<n)
    {
        a=min(s[i].w,tw-w);
        s[i].x=a;
        profit+=a*s[i].r;
        w+=a;
        i++;
    }
    cout<<"Profit : "<<profit<<endl;
    for(i=0; i<n; i++)
        cout<<"Item "<<s[i].k<<" : "<<s[i].x<<"kg"<<endl;
}