#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int lcs(string x,string y,int m,int n)
{
    int i,j;
    int t[m+1][n+1];
    for(i=0;i<=m;i++)
    t[i][0] = 0;
    for(i=0;i<=n;i++)
    t[0][i] = 0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1] == y[j-1])
            t[i][j] = 1+t[i-1][j-1];
            else
            t[i][j] = max(t[i-1][j] , t[i][j-1]);
        }
    }
    return t[m][n];
    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string x;
	    cin>>x;
	    string y;
	    y=x;
	    reverse(y.begin(),y.end());
	    cout<<x.length()-lcs(x,y,x.length(),y.length());
	    cout<<endl;
	}
	return 0;
}
