#include <iostream>
using namespace std;

int scs(string x,string y,int m,int n)
{
    int t[m+1][n+1];
    int i,j;
    for(i=0;i<m+1;i++)
    t[i][0] = 0;
    for(i=0;i<n+1;i++)
    t[0][i] = 0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
             if(x[i-1] == y[j-1])
                t[i][j] = 1+t[i-1][j-1];
                else
               t[i][j] = max(t[i][j-1] , t[i-1][j]);  
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
	    string x,y;
	    cin>>x>>y;
	    int ans = scs(x,y,x.length(),y.length());
	    ans = x.length()+y.length() -ans;
	    cout<<ans<<endl;
	}
	return 0;
}
