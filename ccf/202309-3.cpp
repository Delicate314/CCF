#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
struct item
{
	ll num;
	map<int,int> x; 		//map 左值代表下标，右值代表次幂 
	item(ll num,map<int,int> x):num(num),x(x)   
	{
	}
	item()
	{
		num=0;
		map<int,int> temp;
		x=temp;
	}
};
vector<struct item> poly_add(vector<struct item> l_poly , vector<struct item> r_poly)
{
	vector<struct item> r_temp=l_poly;
	int i;
	for(i=0;i<r_poly.size();i++) r_temp.push_back(r_poly[i]);
	return r_temp;
}

vector<struct item> poly_sub(vector<struct item> l_poly, vector<struct item> r_poly)
{
	vector<struct item> result=l_poly;
	int i,j;
	for(i=0;i<r_poly.size();i++)
	{
		struct item item_temp=r_poly[i];
		item_temp.num*=-1;
		result.push_back(item_temp);
	}
	return result; 
}

struct item item_mul(struct item l_item,struct item r_item)
{
	int i;
	ll num_temp;
	map<int,int> xtemp;
	map<int,int>::iterator it;
	for(it=l_item.x.begin();it!=l_item.x.end();it++)
	{
		xtemp[it->first]=l_item.x[it->first]+r_item.x[it->first];
		r_item.x.erase(it->first);
	}
	for(it=r_item.x.begin();it!=r_item.x.end();it++)
	{
		xtemp[it->first]=r_item.x[it->first];
	}
	num_temp=l_item.num*r_item.num;
	struct item item_temp(num_temp,xtemp);
	return item_temp;
}

vector<struct item> poly_mul(vector<struct item> l_poly, vector<struct item> r_poly)
{
	vector<struct item> result;
	struct item temp;
	int i,j;
	for(i=0;i<l_poly.size();i++)
	{
		for(j=0;j<r_poly.size();j++)
		{
			temp=item_mul(l_poly[i],r_poly[j]);
			result.push_back(temp);
		}
	}
	return result;
}

ll derivative(vector<struct item> vec,int i,map<int,int> value)
{
	ll sum=0,mul;
	int j,k;
	int vtemp;
	for(j=0;j<vec.size();j++)
	{
		mul=1;
		if(vec[j].x.count(i))
		{
			mul=(vec[j].num*vec[j].x[i])%mod;
			vec[j].x[i]--;
			if(vec[j].x[i]==0) 
			{
				vec[j].x.erase(i);
			}
			for(map<int,int>::iterator it=vec[j].x.begin();it!=vec[j].x.end();it++)
			{
				//printf("value[i]: %d\n",value[it->first]);
				vtemp=value[it->first];
				for(k=0;k<it->second;k++) 
				{
					mul=(mul*vtemp)%mod;
				}
			} 
			sum=(sum+mul)%mod;
		}
	}
	return sum;
}

int main()
{
	int n,m;
	int p=0;
	ll sum;
	char c;
	int itemp,vtemp;
	ll res;
	int i,j;
	string input;
	vector<struct item> item_vec,l_poly,r_poly,vec_temp;	//每一个多项式 ；把开始时每一个项都当成只有一项的多项式 
	stack<vector<struct item> > stk; // 每一个item代表多项式的一个项 
	map<int,int>:: iterator it;
	map<int,int> value;
	
	//函数 
	struct item item_mul(struct item l_item,struct item r_item);
	vector<struct item> poly_add(vector<struct item> l_poly,vector<struct item> r_poly);
	vector<struct item> poly_sub(vector<struct item> l_poly,vector<struct item> r_poly);
	vector<struct item> poly_mul(vector<struct item> l_poly,vector<struct item> r_poly);
	int derivative(vector<struct item> vec,int i,map<int,int> value);
	

	cin>>n>>m;
	getchar();
	getline(cin,input);
	while(p<input.size())
	{
		c=input[p++];
		map<int,int> x;
		if(c == 'x')
		{
			x.clear();
			vec_temp.clear();
			itemp=int(input[p++]-'0');
			x[itemp]=1;
			struct item item_temp=item(1,x);
			vec_temp.push_back(item_temp);
			stk.push(vec_temp);
		}
		else if(c == ' ') continue;
		else if(c >='0' && c<='9')
		{
			p--;
			vec_temp.clear();
			sum=0;
			x.clear();
			while(c>='0'&& c<='9')
			{
				sum=sum*10+int(c-'0');
				c=input[++p];
			}
			struct item item_temp=item(sum,x);
			vec_temp.push_back(item_temp);
			stk.push(vec_temp);
		}
		else if(c == '+')
		{
			l_poly=stk.top();
			stk.pop();
			r_poly=stk.top();
			stk.pop();
			vec_temp.clear();
			vec_temp=poly_add(l_poly,r_poly);
			stk.push(vec_temp);
		}
		else if(c == '-')
		{
			c=input[p];
			//减法 
			//负数
			if(c>'0'&&c<='9')
			{
				vec_temp.clear();
				sum=0;
				x.clear();
				while(c>='0'&& c<='9')
				{
					sum=sum*10+int(c-'0');
					c=input[++p];
				}
				sum*=-1;
				struct item item_temp=item(sum,x);
				vec_temp.push_back(item_temp);
				stk.push(vec_temp);
			} 
			else
			{
				r_poly=stk.top();
				stk.pop();
				l_poly=stk.top();
				stk.pop();
				vec_temp.clear();
				vec_temp=poly_sub(l_poly,r_poly);
				stk.push(vec_temp);	
				p++;
			}
		}
		else if(c == '*')
		{
			l_poly=stk.top();
			stk.pop();
			r_poly=stk.top();
			stk.pop();
			vec_temp.clear();
			vec_temp=poly_mul(l_poly,r_poly);
			stk.push(vec_temp);
		}
	}
	vec_temp=stk.top();
	stk.pop();
	/*
	for(i=0;i<vec_temp.size();i++)
	{
		printf("vec_temp %d,:\n",i);
		for(it=vec_temp[i].x.begin();it!=vec_temp[i].x.end();it++)
		{
			printf("x %d 系数：%lld 次幂: %d\n",it->first,vec_temp[i].num,it->second);
		}
	}
	*/
	for(i=0;i<m;i++)
	{
		value.clear();
		cin>>itemp;
		for(j=1;j<=n;j++)
		{
			cin>>vtemp;
			value[j]=vtemp;
		}
		res=derivative(vec_temp,itemp,value);
		res=res<0?res+mod:res;
		printf("%d\n",res);
	}
	return 0;
 } 
