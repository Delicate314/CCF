#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int m,n;
	int i=0,j=0,k=0;
	int flag=1;
	int warehouse[1000][10];
	int sup[1000]={};
	scanf("%d %d",&n,&m);
	for (i=0;i<n;i++) 
	{
		for(j=0;j<m;j++) scanf("%d",&warehouse[i][j]);
		sup[i]=-1;
	}
	
	for(i=0;i<n;i++)
	{
		//判断j是否是i的上级 
		for(j=0;j<n;j++)
		{
			if(j==i) continue;
			//遍历每个编号 
			for(k=0;k<m;k++)
			{
				 //任一个编码小于等于则不是
				if(warehouse[i][k]>=warehouse[j][k]) 
				{
					flag=0;
					break;
				} 
				////j可以做i的上级但i目前找到的是更好的上级
				else if(sup[i]!=-1)
				{
					if(warehouse[sup[i]][k]>warehouse[i][k])
					{
						flag=0;
						break;
					} 	
				}
			}
			// j为i的目前最好上级
			if(flag)
			{
				sup[i]=j;	
			}
			else flag=1;
		}
	}
	for(i=0;i<n;i++) 
	{
		sup[i]++;
		printf("%d\n",sup[i]);	
	}
	return 0;
}
