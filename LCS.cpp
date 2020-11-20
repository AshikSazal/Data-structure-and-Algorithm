#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch[100]="stone",ch2[100]="strong";
    int n1=strlen(ch),n2=strlen(ch2);
    int lcs[n1+1][n2+1],r,c,n=0;
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0||j==0)
                lcs[i][j]=0;
            else if(ch[i-1]==ch2[j-1])
                {
                    lcs[i][j]=1+lcs[i-1][j-1];
                    r=i,c=j;
                    n=lcs[r][j];
                }
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
            cout<<lcs[i][j]<<"\t";
        cout<<endl;
    }
    char st[n+1]={'\0'};
    while(r>0&&c>0)
    {
        if(lcs[r][c]!=lcs[r-1][c]&&lcs[r][c]!=lcs[r][c-1])
        {
            n--;
            st[n]=ch[r-1];
            r--;c--;
        }
        else if(lcs[r][c]==lcs[r-1][c])
            r--;
        else if(lcs[r][c]==lcs[r][c-1])
            c--;
    }
    cout<<st;
}