#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double i;
	map<int,double> gain;
	double sum=0;
	cin>>n>>i;
	for(int j=0;j<=n;j++)
	{
		scanf("%lf",&gain[i]);
		sum+=gain[i]*pow(1+i,(double)-j);
	}
	
	printf("%f",sum);
	return 0;
}
