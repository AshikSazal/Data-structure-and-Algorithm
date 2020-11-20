#include<iostream>
using namespace std;
int s[100][100];
void print(int i,int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        print(i,s[i][j]);
        print(s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    int i,j,k,l,n,d1,d2,flag=0;
    cout<<"How many matrices : ";
    cin>>n;
    int d[n+1];
    int maximum=9999999;
    cout<<"Enter the dimension of each matrix"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>d1>>d2;
        if(i==0)
        {
            d[0]=d1;
            d[1]=d2;
        }
        else
        {
            if(d1!=d[i])
                flag=1;
            d[i+1]=d2;
        }
    }
    if(flag==1)
    {
        cout<<"Multiplication is not possible"<<endl;
        return 0;
    }
    cout<<"Dimension Array:";
    for(i=0; i<n; i++)
        cout<<d[i]<<" ";
    int N[n][n];
    for(i=0; i<=n-1; i++)
        N[i][i]=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            s[i][j]=-1;
    }
    for(l=1; l<=n-1; l++)
    {
        for(i=0; i<=(n-1)-l; i++)
        {
            j=i+l;
            N[i][j]=maximum;
            for(k=i; k<=j-1; k++)
            {
                int cost=N[i][k]+N[k+1][j]+d[i]*d[k+1]*d[j+1];
                if(cost<N[i][j])
                {
                    N[i][j]=cost;
                    s[i][j]=k;
                }
            }
        }
    }
    cout<<"Total multiplication : "<<N[0][n-1]<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout<<s[i][j]<<"\t";
        cout<<endl;
    }
    print(0,n-1);
}