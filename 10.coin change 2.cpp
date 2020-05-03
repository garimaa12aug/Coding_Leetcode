/*Given a value V. You have to make change for V cents, given that you have infinite supply of each of C{ C1, C2, .. , Cm} valued coins. Find the minimum number of coins to make the change.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is V and N, V is the value of cents and N is the number of coins. The second line of each test case contains N input C[i], value of available coins.

Output:
Print the minimum number of coins to make the change, if not possible print "-1".
*/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int count_ways(int coins[],int v,int n)
{
   int t[n+1][v+1];
   t[0][0] = INT_MAX-1;
   int i,j;
   for(i=1;i<=n;i++)
   t[i][0] = 0;
   for(i=1;i<=v;i++)
   t[0][i]=INT_MAX-1;
   j=1;
   for(i=1;j<v+1;j++)
   {
       if(j%coins[0] == 0)
       t[i][j] = j/coins[0];
       else
       t[i][j] = INT_MAX-1;
   }
   for(i=2;i<=n;i++)
   {
       for(j=1;j<=v;j++)
       {
           if(coins[i-1]<=j)
           t[i][j] = min(t[i-1][j] , t[i][j-coins[i-1]]+1);
           if(coins[i-1]>j)
           t[i][j] = t[i-1][j];
       }
   }
   return t[n][v];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int v;
	    cin>>v;
	    int  n;
	    cin>>n;
	    int coins[n];
	    for(int i=0;i<n;i++)
	    cin>>coins[i];
	    int ans = count_ways(coins,v,n);
	    if(ans != INT_MAX-1)
	    cout<<ans;
	    else
	    cout<<"-1";
	    cout<<endl;
	}
	return 0;
}

