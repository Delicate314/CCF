#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	map<int,int>hash;
	int i,j;
	int x,y;
	int count=0;
	cin>>n>>k;
	hash[0]=1;
	for(i=0;i<k;i++)
	{
		cin>>x>>y;
		if(hash[y]==0) count++;
		hash[x]=1;
	} 
	printf("%d",count);
	return 0;
}
