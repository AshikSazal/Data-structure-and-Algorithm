#include<iostream>
using namespace std;
int main()
{
    int s,n,temp;
    cout<<"Total taka : ";
    cin>>s;
    cout<<"How many coins: ";
    cin>>n;
    int v[s+1],coin[n];
    cout<<"which coins : ";
    for(int i=0;i<n;i++)
        cin>>coin[i];
    v[0]=0;
    for(int i=1;i<=s;i++)
        v[i]=INT_MAX;
    for(int i=1;i<=s;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coin[j]<=i)
            {
                temp=v[i-coin[j]];
                if(temp!=INT_MAX&&temp+1<v[i])
                    v[i]=temp+1;
            }
        }
    }
    cout<<"The minimum coin is : "<<v[s];
}