#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int q;
	int n,k;
	int i,j,h;
	int count=0; 
	int temp;
	int rest=1;
	int vis[100001]={};
	int pri[100001]={};
	int nn=100000,m=0,cnt=0;
	vector<int>p,t;
	//�ҳ�1-10^5�ڵ���������
	for ( i = 2; i <= nn; i ++ )//ŷ��ɸ ʱ�临�ӶȻ���ΪO��n��
    {
        if (vis[i] == 0) pri[cnt ++ ] = i;//�������浽pri��
        for ( j = 0; pri[j] * i <= nn; j ++ )//Ҫȷ����ǰ������i��С�ڵ���n��
        {
            vis[pri[j] * i] = 1;
           
            if (i % pri[j] == 0) break;//��ֹ��������ǰ��i������������С��������
        }
    }
	//for(i=0;i<cnt;i++) printf("%d\n",pri[i]);
	
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d %d",&n,&k);
		if(p.size()!=0)
			{
				p.clear();
				t.clear();
			}	
		//����1-10^5�������h,�ж�n�ܲ�������h  
		for(j=0;j<cnt;j++)
		{ 
			h=pri[j];
			if(h>n) break;
			if(n%h==0)
			{
				temp=n;
				//��������������Ҫ�̶ȣ�����count�� 
				do{
					temp=temp/h;
					count++;
				}while(temp%h==0);
				//������Ҫ�̶� 
				if(count>=k)
				{
					p.push_back(h);
					t.push_back(count);
				}
				count=0;
			}	 	 
		}
		
		//���㲢���ʣ����
		if(p.size()==0) printf("1\n");
		else
		{
		for(i=0;i<=p.size()-1;i++)
		{
			for(j=1;j<=t[i];j++)
			{
				rest*=p[i];
			}
		} 
		printf("%d\n",rest);
		rest=1;
		}
	}	
} 
