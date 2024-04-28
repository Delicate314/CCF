#include <bits/stdc++.h>

using namespace std;

int main()
{
	double in[7][12];
	double out[7][12];
	double temp;
	int i,j,k,h;
	for(i=1;i<6;i++)
	{
		for(j=1;j<11;j++) scanf("%lf",&in[i][j]);
	}
	in[0][0]=in[1][1];
	in[6][0]=in[1][1];
	in[0][11]=in[1][10];
	in[6][11]=in[5][10];
	for(j=1;j<=10;j++)
	{
		in[0][j]=in[1][j];
		in[6][j]=in[5][j];
	}
	for(i=1;i<=5;i++)
	{
		in[i][0]=in[i][1];
		in[i][11]=in[i][10];
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=10;j++)
		{
			temp=0;
			for(k=i-1;k<=i+1;k++)
			{
				for(h=j-1;h<=j+1;h++) temp+=in[i][j];
			}
			out[i][j]=round(temp/9);
		}
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=10;j++)
		{
			printf("%lf ",out[i][j]);	
		}
		printf("\n");
	}
	return 0;
 } 
