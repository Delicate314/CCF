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
		//�ж�j�Ƿ���i���ϼ� 
		for(j=0;j<n;j++)
		{
			if(j==i) continue;
			//����ÿ����� 
			for(k=0;k<m;k++)
			{
				 //��һ������С�ڵ�������
				if(warehouse[i][k]>=warehouse[j][k]) 
				{
					flag=0;
					break;
				} 
				////j������i���ϼ���iĿǰ�ҵ����Ǹ��õ��ϼ�
				else if(sup[i]!=-1)
				{
					if(warehouse[sup[i]][k]>warehouse[i][k])
					{
						flag=0;
						break;
					} 	
				}
			}
			// jΪi��Ŀǰ����ϼ�
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
