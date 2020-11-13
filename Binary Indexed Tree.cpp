#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lsb(ll idx)
{
    return idx & (-idx);
}
void update(ll *bit,ll node_idx,ll n,ll val)
{
    // bottom to top
    while(node_idx<=n)
    {
        bit[node_idx]+=val;
        // go to parent
        node_idx+=lsb(node_idx);
    }
}
ll get_sum(ll node_idx,ll *bit)
{
    ll sum=0;
    // Top to bottom
    while(node_idx>=1)
    {
        sum+=bit[node_idx];
        // go to child
        node_idx-=lsb(node_idx);
    }
    return sum;
}
ll *create_bit(ll *a,ll n)
{
    ll *bit=new ll[n+1];
    for(ll i=1;i<=n;i++)
        bit[i]=0;
    for(ll i=1;i<=n;i++)
        update(bit,i,n,a[i]);
    return bit;
}
int main()
{
    ll n,lb,ub,update_val,index;
    cout<<"Enter the size : ";
    cin>>n;
    ll a[n+1];
    cout<<"Enter the element : ";
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll *bit=create_bit(a,n);
    cout<<"Enter the range(a,b) : ";
    cin>>lb>>ub;
    cout<<get_sum(ub,bit)-get_sum(lb-1,bit)<<endl;
    cout<<"Enter the index and update value : ";
    cin>>index>>update_val;
    update(bit,index,n,update_val);
    cout<<"After update"<<endl;
    cout<<"Enter the range(a,b) : ";
    cin>>lb>>ub;
    cout<<get_sum(ub,bit)-get_sum(lb-1,bit)<<endl;
}
