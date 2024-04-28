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
	int n,m,k; //�����ѵ���������n���ٶ����ϵ���Դ����m��ÿ����������ٿ�������k��
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
			//�鿴�Ƿ���Ժϲ�
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
