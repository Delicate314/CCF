#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	int i,j;
	map<int, pair<int,int> > pos,T;
	int xtemp,ytemp;
	int dx,dy;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>dx>>dy;
		T[i]=pair<int,int>(dx,dy);
	}
	for(i=0;i<m;i++)
	{
		cin>>xtemp>>ytemp;
		pos[i]=pair<int,int>(xtemp,ytemp);
	}
	for(i=0;i<n;i++)
	{
		dx=T[i].first;
		dy=T[i].second;
		for(j=0;j<m;j++)
		{
			xtemp=pos[j].first+dx;
			ytemp=pos[j].second+dy;
			pos[j]=pair<int,int>(xtemp,ytemp);
		}
	}
	for(i=0;i<m-1;i++) printf("%d %d\n",pos[i].first,pos[i].second);
	printf("%d %d",pos[i].first,pos[i].second);
	return 0;
}
