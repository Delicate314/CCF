#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,atemp,m;
	int i,j;
	int sum=0; 
	int v;	//�ȼ��ڱ�������ı������� 
	vector<int> a; //���ÿһ����ļ۸� 
	map<int,map<int,int> > dp; //ÿ���۸����С���� 
	cin>>n>>x;
	a.push_back(0);
	for(i=1;i<=n;i++) 
	{
		cin>>atemp;
		sum+=atemp;
		a.push_back(atemp);
	}
	//�൱���������Ϊsum-x�ı������� 
	v=sum-x;
	for(j=0;j<=v;j++) dp[0][j]=0;
	for(i=0;i<=n;i++) dp[i][0]=0; 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=v;j++)
		{
			//�޷������i����Ʒ 
			if(j<a[i]) dp[i][j]=dp[i-1][j];
			//���Է��룬�ȽϷ����i���Ͳ������i������� 
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
		}
		
	}
	m=sum-dp[n][v];
	
	cout<<m;
	return 0;
}
