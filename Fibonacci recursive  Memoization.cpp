#include<iostream>
#include<cstring>
using namespace std;
int fun(int fib[],int n)
{a++;
    if(n<=1)
        return n;
    if(fib[n]>=0)
        return fib[n];
    else
    {
        fib[n]=fun(fib,n-2)+fun(fib,n-1);
        return fib[n];
    }
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    int fib[n+1];
    memset(fib,-1,sizeof(fib));
    int sum=fun(fib,n);

    cout<<sum<<endl;
}