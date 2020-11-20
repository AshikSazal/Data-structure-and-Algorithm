#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector< vector<int> >v,int weight[],int prof[],int n,int i,int j)
{
    if(i==0 || j==0)
        return 0;
    if(v[i][j] !=-1)
        return v[i][j];
    int taka,leave;
    if (weight[i]>j)
    {
        return knapsack(v,weight,prof,n,i-1,j);
    }
    else
    {
        leave=knapsack(v,weight,prof,n,i-1,j);
        taka=knapsack(v,weight,prof,n,i-1,j-weight[i])+prof[i];
    }
    v[i][j]=max(taka,leave);
    return v[i][j];
}
int main()
{
    int n;
    cout<<"How many element:";
    cin>>n;
    int weight[n+1],prof[n+1];
    weight[0]=0;
    prof[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>weight[i]>>prof[i];
    }
    int s;
    cout<<"Enter the size of knapsack:";
    cin>>s;
    vector<vector<int> >v(n+1,vector<int>(s+1,-1));
    int z=knapsack(v,weight,prof,n,n,s);
    cout<<"The max prof is:"<<z<<endl;
    return 0;
}