#include <bits/stdc++.h>
using namespace std;
int *pre_fun(int m,char p[])
{
    static int arr[100];
    int k=0;
    arr[0]=0;
    for(int i=1;i<m;i++)
    {
        while(k>0&&p[k]!=p[i])
            k=arr[k-1];
        if(p[k]==p[i])
            k=k+1;
        arr[i]=k;
    }
    return arr;

}
int main()
{
    char T[]="abcxabcdabxabcdabcdabcy";
    char P[]="abcdabcy";
    int n=sizeof(T)-1,m=sizeof(P)-1;
    int *arr=pre_fun(m,P);
    int q=0;
    for(int i=0;i<n;i++)
    {
        while(q>0&&P[q]!=T[i])
            q=arr[q-1];
        if(P[q]==T[i])
            q=q+1;
        if(q==m)
        {
            cout<<"Pattern occurs : "<<i-(m-1)<<endl;
            break;
        }
    }
}