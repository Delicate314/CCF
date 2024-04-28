#include<cstdio>
#include<iostream>
#include<vector>
#include<queue> 
using namespace std;
struct Land
{
	int t;
	int c;
	bool operator <(const Land& a) const
	{
		return t<a.t;
	}
};

int main()
{
	int n,m,k; //待开垦的区域总数n、顿顿手上的资源数量m和每块区域的最少开垦天数k。
	int ttemp,ctemp;
	struct Land ltemp;
	priority_queue<Land> land;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&ltemp.t,&ltemp.c);
		land.push(ltemp);
	}
	do
	{
		ltemp.c=land.top().c;
		ltemp.t=land.top().t;
		land.pop();
		if(m<ltemp.c||ltemp.t==k) 
		{
			land.push(ltemp);
			break;
		}
		else 
		{
			ltemp.t-=1;
			m-=ltemp.c;
			//查看是否可以合并
			if(ltemp.t==land.top().t)
			{
				ltemp.c+=land.top().c;
				land.pop();
			} 
			land.push(ltemp);
		}
	}while(m>=0);
	printf("%d",land.top().t);
	return 0;
}
