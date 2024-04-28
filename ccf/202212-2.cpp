#include<bits/stdc++.h>
using namespace std;

int main()
{
	const int num=1000;
	int q,k;
	long long n,res;
	int i,j,m,temp,ntemp,vtemp;
	int t;
	map<int,int> prime;
	prime[0]=2;
	for(i=3;i<=num;i++)
	{
		ntemp=prime.size();
		for(j=0;j<ntemp;j++)
		{
			if(i%prime[j] ==0) break;
		}
		if(j==ntemp)
		{
			prime[ntemp]=i;
		}
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>n>>k;
		res=1;
		for(m=0;m<prime.size();m++)
		{
			vtemp=prime[m];
			if(n<vtemp) break;
			else if(n%vtemp==0)
			{
				t=0;
				while(n%vtemp==0) 
				{
					t++;
					n/=vtemp;
				}
				if(t>=k)
				while(t-->0) res*=vtemp;
			}	
		}
		cout<<res<<endl;
	}
	
	return 0;
 } 
