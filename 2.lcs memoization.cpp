#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int t[102][102];

int lcs(string x,string y,int a,int b)
{
    if(a==0 || b==0)
    return 0;
    if(t[a][b] != -1)
    return t[a][b];
    if(x[a-1] == y[b-1])
    return  t[a][b] = 1+lcs(x,y,a-1,b-1);
    else
    return t[a][b] = max(lcs(x,y,a-1,b) , lcs(x,y,a,b-1));
}

int find_lcs(string x,string y, int a, int b)
{
    memset(t,-1,sizeof(t));
    return lcs(x,y,a,b);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
	    string x;
	    string y;
	    cin>>x>>y;
	    cout<<find_lcs(x,y,a,b);
	    cout<<endl;
	}
	return 0;
}
