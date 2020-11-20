#include <iostream>
using namespace std;
int coinc(int v[],int coin[],int s,int n)
{
    if(s<1)
        return 0;
    if(v[s]!=999999)
        return v[s];
    for(int i=0;i<n;i++)
    {
        if(coin[i]<=s)
        {
            int temp=coinc(v,coin,s-coin[i],n);
            if(v[s]>temp+1)
                v[s]=temp+1;
        }
    }
    return v[s];
}
int main()
{
    int s,n,result;
    cout<<"Total taka : ";
    cin>>s;
    cout<<"How many coins : ";
    cin>>n;
    int v[s+1],coin[n];
    cout<<"Which coins : ";
    for(int i=0;i<n;i++)
        cin>>coin[i];
    for(int i=0;i<=s;i++)
        v[i]=999999;
    result=coinc(v,coin,s,n);
    cout<<"The minimum coin is : "<<result;
}