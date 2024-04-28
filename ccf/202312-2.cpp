#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int q;
	int n,k;
	int i,j,h;
	int count=0; 
	int temp;
	int rest=1;
	int vis[100001]={};
	int pri[100001]={};
	int nn=100000,m=0,cnt=0;
	vector<int>p,t;
	//找出1-10^5内的所有素数
	for ( i = 2; i <= nn; i ++ )//欧拉筛 时间复杂度基本为O（n）
    {
        if (vis[i] == 0) pri[cnt ++ ] = i;//将质数存到pri中
        for ( j = 0; pri[j] * i <= nn; j ++ )//要确保当前质数的i倍小于等于n。
        {
            vis[pri[j] * i] = 1;
           
            if (i % pri[j] == 0) break;//终止条件（当前数i遇到了它的最小质因数）
        }
    }
	//for(i=0;i<cnt;i++) printf("%d\n",pri[i]);
	
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d %d",&n,&k);
		if(p.size()!=0)
			{
				p.clear();
				t.clear();
			}	
		//遍历1-10^5间的素数h,判断n能不能整除h  
		for(j=0;j<cnt;j++)
		{ 
			h=pri[j];
			if(h>n) break;
			if(n%h==0)
			{
				temp=n;
				//能整除，计算重要程度（次幂count） 
				do{
					temp=temp/h;
					count++;
				}while(temp%h==0);
				//满足重要程度 
				if(count>=k)
				{
					p.push_back(h);
					t.push_back(count);
				}
				count=0;
			}	 	 
		}
		
		//计算并输出剩余项
		if(p.size()==0) printf("1\n");
		else
		{
		for(i=0;i<=p.size()-1;i++)
		{
			for(j=1;j<=t[i];j++)
			{
				rest*=p[i];
			}
		} 
		printf("%d\n",rest);
		rest=1;
		}
	}	
} 
