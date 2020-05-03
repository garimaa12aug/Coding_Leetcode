  

#include<bits/stdc++.h>
using namespace std;


bool subset_sum(int arr[], int n, int w) 
{ 
  if(w==0)
  return 1;
  if(n==0 && w!=0)
  return 0;
   
   if(arr[n-1] <=w)
   {
       return subset_sum(arr,n-1,w-arr[n-1]) || subset_sum(arr,n-1,w);
   }
   else if(arr[n-1]>w)
   return subset_sum(arr,n-1,w);
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
	    int sum=0;
	    for(i=0;i<n;i++)
	    sum += arr[i];
	    if(sum%2 !=0)
	    cout<<"NO";
	    else
	    {
	    if(subset_sum(arr,n,sum/2))
	    cout<<"YES";
	    else
	    cout<<"NO";
	    }
	    cout<<endl;
	}
	return 0;
}
