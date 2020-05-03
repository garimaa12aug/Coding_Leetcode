#include <iostream>
using namespace std;


int count_subsets(int arr[],int n,int w)
{
    if(w==0)
    return 1;
    if(n==0 && w!=0)
    return 0;
    
    if(arr[n-1] <=w)
    return count_subsets(arr,n-1,w) + count_subsets(arr,n-1,w-arr[n-1]);
    else
    return count_subsets(arr,n-1,w);
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
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int sum;
	    cin>>sum;
	    cout<<count_subsets(arr,n,sum);
	    cout<<endl;
	}
	return 0;
}
