#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,atemp,m;
	int i,j;
	int sum=0; 
	int v;	//等价于背包问题的背包容量 
	vector<int> a; //存放每一本书的价格 
	map<int,map<int,int> > dp; //每个价格的最小花费 
	cin>>n>>x;
	a.push_back(0);
	for(i=1;i<=n;i++) 
	{
		cin>>atemp;
		sum+=atemp;
		a.push_back(atemp);
	}
	//相当于求解容量为sum-x的背包问题 
	v=sum-x;
	for(j=0;j<=v;j++) dp[0][j]=0;
	for(i=0;i<=n;i++) dp[i][0]=0; 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=v;j++)
		{
			//无法放入第i件物品 
			if(j<a[i]) dp[i][j]=dp[i-1][j];
			//可以放入，比较放入第i个和不放入第i个的情况 
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
		}
		
	}
	m=sum-dp[n][v];
	
	cout<<m;
	return 0;
}
