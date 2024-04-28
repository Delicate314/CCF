#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<int,map<int,int> > A;
	map<int,map<int,int> > B;
	vector<pair<int,int> > Tree;  //藏宝图里树的位置 
	int n,L,S;
	int i,j,k;
	int xtemp,ytemp,vtemp; 
	int x,y;
	int stop_flag,match_flag;
	int count=0;
	int vtemp1,vtemp2;
	cin>>n>>L>>S;
	for(i=0;i<n;i++)
	{
		cin>>xtemp>>ytemp;
		A[xtemp][ytemp]=1;
		//存放地图中所有树的位置方便遍历 
		Tree.push_back(pair<int,int>(xtemp,ytemp));
	}
	for(i=S;i>=0;i--)
	{
		for(j=0;j<=S;j++) 
		{
			cin>>vtemp;
			B[i][j]=vtemp;
		}
	}
	//开始查找符合条件的树
	for(i=0;i<Tree.size();i++)
	{
		//以x,y作为与藏宝图左下角的树对应的树进行遍历 
		x=Tree[i].first;
		y=Tree[i].second;
		if(x+S>L||y+S>L) break;
		match_flag=1;
		for(j=0;j<=S;j++)
		{
			if(stop_flag) 
			{
				stop_flag=0;
				match_flag=0;
				break;
			}
			for(k=0;k<=S;k++)
			{
				vtemp1=A[x+j][y+k];
				vtemp2=B[j][k];
				if(vtemp1!=vtemp2)
				{
					stop_flag=1;
					match_flag=0;
					break;
				}
			}		
		}
		if(match_flag) count++;
	} 
	printf("%d",count);
	return 0;
}
