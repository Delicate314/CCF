#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,i;
	map<int,int> a,b;
	map<int,int> c;
	cin>>n>>m;
	c[0]=1;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=c[i-1]*a[i];
	}
	for(i=n;i>=1;i--)
	{
		b[i]=m/c[i-1];
		m=m%c[i-1];
	}
	for(i=1;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	printf("%d",b[i]);
	
	
	
	return 0;
}
