#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	map<int,pair<int,double> > T;
	map<int,pair<int,int> > T_ij;
	map<int,pair<double,double> >pos;
	double xtemp,ytemp,vtemp;
	int i,j,itemp,jtemp;
	int typetemp;
	double k_temp,theta_temp;	//从T1到Ti，总的k和theta是多少（运用类似差分计算） 
	map<int,double> k,theta;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>typetemp>>vtemp;
		T[i]=pair<int,double>(typetemp,vtemp);
		k[i]=1;
		theta[i]=0;
	}
	for(i=0;i<m;i++)
	{
		cin>>itemp>>jtemp>>xtemp>>ytemp;
		pos[i]=pair<double,double>(xtemp,ytemp);
		T_ij[i]=pair<int,int>(itemp,jtemp);
	}
	
	k[0]=1;
	theta[0]=0;
	for(i=1;i<=n;i++)
	{
		typetemp=T[i].first;
		vtemp=T[i].second;
		if(typetemp==1)
		{
			k_temp=k[i-1];
			k[i]=k[i-1]*vtemp;
			theta[i]=theta[i-1];
		}
		else
		{
			theta_temp=theta[i-1];
			theta[i]=theta[i-1]+vtemp;
			k[i]=k[i-1];
		}
	}

	for(i=0;i<m;i++)
	{
		xtemp=pos[i].first;
		ytemp=pos[i].second;
		itemp=T_ij[i].first;
		jtemp=T_ij[i].second;
		k_temp=k[jtemp]/k[itemp-1];
		theta_temp=theta[jtemp]-theta[itemp-1];
		xtemp*=k_temp;
		ytemp*=k_temp;
		pos[i].first=xtemp*cos(theta_temp)-ytemp*sin(theta_temp);
		pos[i].second=xtemp*sin(theta_temp)+ytemp*cos(theta_temp);
	}
	for(i=0;i<m-1;i++) printf("%f %f\n",pos[i].first,pos[i].second);
	printf("%f %f",pos[i].first,pos[i].second);
	return 0;
}
