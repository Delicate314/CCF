#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double mean,var;
	map<int,int> a;
	map<int,double> f;
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		mean+=(double)a[i]/n;
	}
	for(int i=0;i<n;i++)
	{
		var+=(a[i]-mean)*(a[i]-mean)/n;
	}
	for(int i=0;i<n;i++)
	{
		f[i]=(a[i]-mean)/sqrt(var);
	}
	for(int i=0;i<n-1;i++) printf("%f\n",f[i]);
	printf("%f",f[n-1]);
	return 0;
 } 
