#include<bits/stdc++.h>
using namespace std;

int main()
{
	int compute_sum(char c,int j,int k);
	int n;
	map<string,int> status;
	int i,j,k;
	char chess[64];
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<64;j++) cin>>chess[j];
		if(status.count(chess)) status[chess]++;
		else status[chess]=1;
		cout<<status[chess]<<endl;
	}
	return 0;
 } 
