/*Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
*/

#include <iostream>
using namespace std;

int t

int lcs(string x,string y,int a,int b)
{
    if(a==0 || b==0)
    return 0;
    if(x[a-1] == y[b-1])
    return 1+lcs(x,y,a-1,b-1);
    else
    return max(lcs(x,y,a-1,b) , lcs(x,y,a,b-1));
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
	    string x;
	    string y;
	    cin>>x>>y;
	    cout<<lcs(x,y,a,b);
	    cout<<endl;
	}
	return 0;
}
