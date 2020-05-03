#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int t[1001][1001];

int knapsack(int wt[],int val[],int w,int n)
{
    if(n==0 || w==0)
    return 0;
    if(t[n][w] !=-1)
    return t[n][w];
    if(wt[n-1] <=w)
    {
        return t[n][w] = max((val[n-1] + knapsack(wt,val,w-wt[n-1],n-1)), knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1] >w)
    return t[n][w] = knapsack(wt,val,w,n-1);
}

int knapsack_find(int wt[],int val[],int w,int n)
{
    memset(t, -1, sizeof(t));
   return  knapsack(wt,val,w,n);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int w;
	    cin>>w;
	    int val[n];
	    int wt[n];
	    int i,j;
	    for(i=0;i<n;i++)
	    cin>>val[i];
	    for(i=0;i<n;i++)
	    cin>>wt[i];
	    //memset(t,-1,sizeof(t));
	     
	   //int i,j;
	    cout<<knapsack_find(wt,val,w,n)<<endl;
	}
	return 0;
}
