/*
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:
Print number of possible ways to make change for N cents.
*/

#include <iostream>
using namespace std;

int count_ways(int arr[],int m,int n)
{
    int t[m+1][n+1];
    int i,j;
    t[0][0] = 1;
    for(i=1;i<=m;i++)
    t[i][0] = 1;
    for(i=1;i<=n;i++)
    t[0][i] = 0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(arr[i-1] <=j)
            t[i][j] = t[i-1][j] + t[i][j-arr[i-1]];
            if(arr[i-1]>j)
            t[i][j] = t[i-1][j];
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
	    int m;
	    cin>>m;
	    int arr[m];
	    for(int i=0;i<m;i++)
	    cin>>arr[i];
	    int n;
	    cin>>n;
	    cout<<count_ways(arr,m,n)<<endl;
	}
	return 0;
}
