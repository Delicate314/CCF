#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,N;
	map<int,int> A;
	int i,j;
	int atemp;
	int sum=0;
	int index_temp=1;
	A[0]=0;
	cin>>n>>N;
	for(i=1;i<=n;i++)
	{
		cin>>atemp;
		A[i]=atemp;
	}
	for(i=1;i<N;i++)
	{
		for(j=index_temp;j<=n;j++)
		{
			atemp=A[j];
			if(i>=atemp)
			{
				if(index_temp==n) sum+=n;
				else index_temp++;
				continue;
			}
			else if(i<atemp)
			{
				sum+=index_temp-1;
				break;
			}
		}
	}
	printf("%d",sum);
	return 0;
}
