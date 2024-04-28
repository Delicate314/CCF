#include<bits/stdc++.h>

using namespace std;

int main()
{
	map<int,map<int,int> > m;
	m[1][1]=2;
	printf("%d",m[3][3]);
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++) printf("%d ",m[i][j]);
	return 0;
 } 
