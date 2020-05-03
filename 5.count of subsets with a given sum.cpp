#include <iostream>
using namespace std;


int count_subsets(int arr[],int n,int w)
{
    int i,j;
    int t[n+1][w+1];
    for(i=0;i<n+1;i++)
    t[i][0] = 1;
    for(i=1;i<w+1;i++)
    t[0][i] = 0;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<w+1;j++)
        {
            if(arr[i-1] <=j)
            t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            if(arr[i-1] >j)
            t[i][j] = t[i-1][j];
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
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int sum;
	    cin>>sum;
	    cout<<count_subsets(arr,n,sum);
	    cout<<endl;
	}
	return 0;
}
