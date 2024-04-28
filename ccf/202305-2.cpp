#include<bits/stdc++.h>
using namespace std;
map<int,map<int,long long> > dot_product(map<int,long long> W,map<int,map<int,long long> > B,int n,int d)
{
	map<int,map<int,long long> >result;
	int i,j;
	long long wtemp,btemp;
	for(i=1;i<=n;i++)
	{
		wtemp=W[i];
		for(j=1;j<=d;j++) 
		{
			btemp=B[i][j];
			result[i][j]=wtemp*btemp;
		}
	}
	return result;
}

map<int,map<int,long long> > product(map<int,map<int,long long> > A, map<int,map<int,long long> > B,int l1,int c1,int l2,int c2)
{
	map<int,map<int,long long> >result;
	int i,j,k,m;
	long long atemp,btemp,sum;
	for(i=1;i<=l1;i++)
	{
		for(j=1;j<=c2;j++)
		{
			sum=0;
			for(k=1;k<=l2;k++)
			{
				atemp=A[i][k];
				btemp=B[k][j];
				sum+=atemp*btemp;
			}
			result[i][j]=sum;
		}
	}
	return result;
}
int main()
{
	map<int,map<int,long long> > Q,K_trans,V,res,K_V,Q_K_V;
	map<int,long long> W;
	int n,d;
	int i,j;
	int vtemp;
	map<int,map<int,long long> > dot_product(map<int,long long> A,map<int,map<int,long long> > B,int n,int d);
	map<int,map<int,long long> > product(map<int,map<int,long long> > A, map<int,map<int,long long> > B,int l1,int c1,int l2,int c2);
	cin>>n>>d;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=d;j++)
		{
			cin>>vtemp;
			Q[i][j]=vtemp;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=d;j++)
		{
			cin>>vtemp;
			K_trans[j][i]=vtemp;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=d;j++)
		{
			cin>>vtemp;
			V[i][j]=vtemp;
		}
	}
	for(i=1;i<=n;i++)
	{
		cin>>vtemp;
		W[i]=vtemp;
	}
	K_V=product(K_trans,V,d,n,n,d);
	

	Q_K_V=product(Q,K_V,n,d,d,d);


	res=dot_product(W,Q_K_V,n,d);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=d;j++)
		{
			cout<<res[i][j]<<" ";
		}
		printf("\n");
	}
	return 0;
}
