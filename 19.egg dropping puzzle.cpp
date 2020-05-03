#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int t[51][51];

int solve(int n,int f)
{
    if(n==1 || f==0|| f==1)
    return f;
    if(t[n][f] !=-1)
    return t[n][f];
    int min_val = INT_MAX;
    for(int k =1;k<=f;k++)
    {
        int temp = 1+max(solve(n-1,k-1) , solve(n,f-k));
        min_val = min(min_val,temp);
    }
    return t[n][f] =  min_val;
}

int solve_for(int n,int k)
{
    memset(t,-1,sizeof(t));
    return solve(n,k);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    cout<<solve_for(n,k)<<endl;
	}
	return 0;
}
