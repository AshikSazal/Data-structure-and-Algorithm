#include<iostream>
using namespace std;
int main()
{
    int n,i,w,m,take,leave;
    cout<<"Enter the maximum weight of knapsack : ";
    cin>>m;
    cout<<"How many items : ";
    cin>>n;
    int p[n+1],weight[n+1];
    p[0]=0,weight[0]=0;
    cout<<"What is the Profit & Weight?\n";
    for(i=1;i<=n;i++)
    {
        cin>>p[i]>>weight[i];
    }
    int v[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=m;w++)
        {
            if(i==0||w==0)
                v[i][w]=0;
            else if(weight[i]>w)
                v[i][w]=v[i-1][w];
            else
            {
                leave=v[i-1][w];
                take=p[i]+v[i-1][w-weight[i]];
                v[i][w]=max(leave,take);
            }
        }
    }
    cout<<"The maximum profit is : "<<v[n][m]<<endl;
    i=n,w=m;
    cout<<"The index is : ";
    while(i>0&&w>0)
    {
        if(v[i][w]!=v[i-1][w])
        {
            cout<<i<<" ";
            w=w-weight[i];
        }
        i--;
    }
}