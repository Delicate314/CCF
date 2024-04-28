#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

struct Land
{
	int t;
	int c;
};

int main()
{
	//二分法 
	int n,m,k; //待开垦的区域总数n、顿顿手上的资源数量m和每块区域的最少开垦天数k。
	vector <Land> land;
	int ttemp,ctemp,mtemp;
	int left,right,mid,least;                                                                                                                                                                                                                                                                                                                                                                                                                                                 
	struct Land ltemp;
	scanf("%d %d %d",&n,&m,&k);
		for(int i=0;i<n;i++)
	{
		scanf("%d %d",&ltemp.t,&ltemp.c);
		land.push_back(ltemp);
	}
	left=k;
	right=land.front().t;
	least=right;
	while(1)
	{
		mtemp=m;
		for(int i =0;i<n;i++)
		{
			if(least>land[i].t) continue;
			else
			{
				mtemp-=(land[i].t-least)*land[i].c;
			}
		}
		if(mtemp<0) 
		{
			least++;
			break;
		}
		else 
		{
			if(least == k) break;
			least--;
		}
	}
	printf("%d",least);
	return 0;
}
