#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,count=0,flag=0,temp;
	int matrix[8][8]={};
	int M[8][8]={};
	int T,data;
	int i,j;
	int u,v;
	int multiple[8][8]={};
	int M_2[8][8]={};
	double DCT[8][8]={};
	double alpha_u,alpha_v,alpha_u1,alpha_v1,alpha_u2,alpha_v2;
	double sum,pi;
	//读入图像矩阵 
	for(i=0;i<=7;i++)
		for(j=0;j<=7;j++) cin>>matrix[i][j];
	cin>>n;
	cin>>T;
	//读入量化矩阵
	i=0;j=0;
	cin>>M[i][j];
	j++;count++;
	if(count == n) flag=1;
	while(!(i==7 && j==1))
	{
		if(flag) break;
		if(i==0)
		{
			do
			{
				cin>>temp;
				M[i][j]=temp;
				count++;
				if(count == n)
				{
					flag=1;
					break;
				}
				i++;j--;	
			}while(j!=0);
			if(!flag)
			{
				cin>>temp;
				M[i][j]=temp;
				count++;
				if(count == n)
				{
					flag=1;
					break;
				}
				if(i!=7) i++;
				else j++;
			}
		}
		else if(j==0)
		{
			do
			{
				cin>>temp;
				M[i][j]=temp;
				count++;
				if(count == n)
				{
					flag=1;
					break;
				}
				i--;j++;
			}while(i!=0);
			if(!flag)
			{
				cin>>temp;
				M[i][j]=temp;
				count++;
				j++;	
			}	
		}
	}
	while(!(i+j==14))
	{
		if(flag) break;
		if(i==7)
		{
			do
			{
				cin>>temp;
				M[i][j]=temp;
				count++;
				if(count == n)
				{
					flag=1;
					break;
				}
				i--;j++;	
			}while(j!=7);
			if(!flag)
			{
				cin>>temp;
				M[i][j]=temp;
				count++;
				if(count == n) flag=1;
				i++;
			}
		}
		else if(j==7)
		{
			do
			{
				cin>>temp;
				M[i][j]=temp;
				count++;
				if(count == n)
				{
					flag=1;
					break;
				}
				i++;j--;
			}while(i!=7);
			if(!flag)
			{
				cin>>temp;
				M[i][j]=temp;
				count++;
				if(count == n) flag=1;
				j++;	
			}	
		}
	}
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++) multiple[i][j]=matrix[i][j]*M[i][j];
	}
	/*
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++) cout<<M[i][j]<<" ";
		cout<<endl;
	}
	*/
	//T=0,输出填充后图像矩阵
	if(T == 0)
	{
		for(i=0;i<=7;i++)
		{
			for(j=0;j<=7;j++) cout<<M[i][j]<<" ";
			cout<<endl;
		}		
	} 
	//T=1,输出量化后矩阵 
	else if(T == 1)
	{
		for(i=0;i<=7;i++)
		{
			for(j=0;j<=7;j++) cout<<multiple[i][j]<<" ";
			cout<<endl;
		}
	}
	//T=2,输出最终解码结果 
	else if(T == 2)
	{
		alpha_v1=alpha_u1=sqrt((double)1/2);
		alpha_v2=alpha_u2=1;
		pi=acos(-1);
		for(i=0;i<=7;i++)
		{
			for(j=0;j<=7;j++)
			{
				sum=0;
				for(u=0;u<=7;u++)
				{
					if(u==0) alpha_u=alpha_u1;
					else alpha_u=alpha_u2;
					for(v=0;v<=7;v++)
					{
						if(v==0) alpha_v=alpha_v1;
						else alpha_v=alpha_v2;
						sum+=alpha_u*alpha_v*(double)multiple[u][v]*cos(pi/8*(i+0.5)*u)*cos(pi/8*(j+0.5)*v);
					}
				}
				sum/=4;
				DCT[i][j]=sum;
			}
		}

		for(i=0;i<=7;i++)
		{
			for(j=0;j<=7;j++)
			{
				M_2[i][j]=(int)round(DCT[i][j])+128;
				if(M_2[i][j]>255) M_2[i][j]=255;
				else if(M_2[i][j]<0) M_2[i][j]=0;
				cout<<M_2[i][j]<<" ";
			}
			cout<<endl;
		}
		
	}
	return 0;
 } 
