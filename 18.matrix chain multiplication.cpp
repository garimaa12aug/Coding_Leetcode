#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int t[101][101];

int solve(int arr[],int i,int j)
{
    
    if(i>=j)
    return 0;
    if(t[i][j] !=-1)
    return t[i][j];
    int min_val = INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp = solve(arr,i,k)+solve(arr,k+1,j)+ (arr[i-1] * arr[k] * arr[j]);
        min_val = min(min_val,temp);
        //t[i][j] = min_val;
    }
    return t[i][j] = min_val;
}

int solve_for(int arr[],int i,int j)
{
    memset(t,-1,sizeof(t));
    return solve(arr,i,j);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i;
	    int arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    cout<<solve_for(arr,1,n-1)<<endl;
	}
	return 0;
}
