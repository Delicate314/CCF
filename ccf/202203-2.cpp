#include<bits/stdc++.h>
using namespace std;

int main()
{
	const int N=200001;
	int n,m,k;
	map<int,pair<int,int> > plan;
	map<int,int> q,result;
	int i,j;
	int l,r;
	int ttemp,ctemp,qtemp;
	int get_time;
	int count=0;
	cin>>n>>m>>k;
	for(i=0;i<n;i++)
	{
		 cin>>ttemp>>ctemp;
		 plan[i]=pair<int,int>(ttemp,ctemp);
	}
	for(i=0;i<m;i++)
	{
		cin>>qtemp;
		q[i]=qtemp;
	}
	for(i=0;i<n;i++) 
	{
		ctemp=plan[i].second;
		ttemp=plan[i].first;
		l=max(0,ttemp-ctemp-k+1);
		r=max(0,min(N,ttemp-k));
		result[l]+=1;
		result[r+1]-=1;
	}
	for(i=1;i<=q[m-1];i++) result[i]+=result[i-1];
	for(i=0;i<m-1;i++) printf("%d\n",result[q[i]]);
	printf("%d",result[q[i]]);
	return 0;
}
