  

#include<bits/stdc++.h>
using namespace std;


bool subset_sum(int arr[], int n, int w) 
{ 
    bool t[n+1][w+1]; 
   for (int i = 0; i <= n; i++) 
      t[i][0] = true; 
   for (int i = 1; i <= w; i++) 
      t[0][i] = false; 
   for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= w; j++) 
       { 
         if(j<arr[i-1]) 
         t[i][j] = t[i-1][j]; 
         if (j >= arr[i-1]) 
           t[i][j] = t[i-1][j] ||  t[i - 1][j-arr[i-1]]; 
       } 
     } 
   return t[n][w]; 
} 

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    int i;
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    int sum;
	    cin>>sum
	    if(subset_sum(arr,n,sum))
	    cout<<"YES";
	    else
	    cout<<"NO";
	    
	    cout<<endl;
	}
	return 0;
}
