#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int lcs(string x,string y,int m,int n)
{
    int t[m+1][n+1];
    int i,j;
    for(i=0;i<m+1;i++)
    t[i][0]=i;
    for(i=0;i<n+1;i++)
    t[0][i]=i;
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(x[i-1] == y[j-1])
            t[i][j] = t[i-1][j-1];
            else
            t[i][j] = 1+min(t[i-1][j] , min(t[i][j-1],t[i-1][j-1]));
        }
    }
    return t[m][n];
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int p,q;
        cin>>p>>q;
        string x;
        string y;
        cin>>x>>y;
        int ans1;
        ans1 = lcs(x,y,p,q);
       cout<<ans1<<endl;
    }
}
