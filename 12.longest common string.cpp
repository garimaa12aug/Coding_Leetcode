#include <iostream>
using namespace std;

int substring(string x,string y,int m,int n)
{
    int t[m+1][n+1];
    int i,j;
    for(i=0;i<m+1;i++)
    t[i][0]=0;
    for(i=0;i<n+1;i++)
    t[0][i] = 0;
    int result =0;
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(x[i-1] == y[j-1])
            {
                t[i][j] = 1+t[i-1][j-1];
                result = max(result,t[i][j]);
            }
            else
            t[i][j] =0;
        }
    }
    return result;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    string x;
	    string y;
	    cin>>x>>y;
	    cout<<substring(x,y,n,m);
	    cout<<endl;
	    
	}
	return 0;
}
