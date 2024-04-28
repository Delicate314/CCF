#include<bits/stdc++.h>
using namespace std;
struct Value
{
	int num;
	int value;
};
vector<int> duanyan(map<int,vector<Value> > Attr,int attr_num,int value)
{
	vector<int> out;
	for(int i=1;i<=Attr.size();i++)
	{
		for(int j=0;j<Attr.size();j++)
		{
			if(Attr[i][j].num == attr_num)
			{
				if(Attr[i][j].value == value)
				{
				out.push_back(i);
				break;
				}
			}
		}
	 } 
	return out;
}

vector<int> fanduanyan(map<int,vector<Value> > Attr,int attr_num,int value)
{
	vector<int> out;
	int num_temp,value_temp;
	for(int i=1;i<=Attr.size();i++)
	{
		for(int j=0;j<Attr.size();j++)
		{
			num_temp=Attr[i][j].num;
			if(num_temp == attr_num)
			{
				value_temp= Attr[i][j].value;
				if(value_temp != value)
				{
				out.push_back(i);
				break;
				}
			}
		}
	 } 
	return out;
}
int main()
{
	int n;
	int attr_temp,num_temp,dn; 
	int i,j,k,m;
	int p1,p2,pn; //表达式（字符数组)的下标 ,pn为当前下标 
	char sign_pop; //现在从栈里取出的符号 
	int sum;		//读取到的数字 
	int attr_num,value; 
	char str[2001];
	map<int,vector<Value> > Attr;  //属性集合，下标为dn值 
	struct Value vtemp;
	vector<int> temp;	//符号运算得出的集合暂存 
	bitset<500> bit_res[2501];  //存放原子表达式的结果 
	stack<char> sign;   //用一个栈存放符号 
	stack<int> stk; //用一个栈存放数字 
	stack<vector<int> > result; //用一个栈存放中间/表达式最终结果 
	vector<int> v1,v2,v3; //用作&和|运算 
	vector<vector<int> > final_result; //用一个容器存放最终输出的结果 
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>dn>>k;  //dn值，从1开始 
		for(j=0;j<k;j++)
		{
			cin>>vtemp.num>>vtemp.value; //编号和对应属性值
			Attr[dn].push_back(vtemp);
		}
	}
	cin>>m;
	for(i=0;i<m;i++)
	{
		scanf("%s",str);
		pn=0;
		do
		{
			//表达式当前位字符/数字入对应的栈 
			if(str[pn]=='&' || str[pn]=='|' || str[pn]==':'|| str[pn]=='~')
			{
				sign.push(str[pn++]);
			}
			else if(str[pn]>'0'&&str[pn]<='9')
			{
				//读取这个数
				sum=0;
				do
				{
					sum+=sum*10+(int)(str[pn++]-'0');
				}while(str[pn]>='0' && str[pn]<='9');
				stk.push(sum);
			}
			//读取到右括号，则取出一个符号位进行运算 
			else if(str[pn]==')')
			{
				pn++;
				sign_pop=sign.top();
				sign.pop();
				if(sign_pop == ':') 
				{
					value = stk.top();
					stk.pop();
					attr_num = stk.top();
					stk.pop();
					temp=duanyan(Attr,attr_num,value);
			
					result.push(temp);
				}
				else if(sign_pop == '~')
				{
					value = stk.top();
					stk.pop();
					attr_num = stk.top();
					stk.pop();
					temp=fanduanyan(Attr,attr_num,value);
					
					result.push(temp);
				}
				else if(sign_pop == '&')
				{
					v1=result.top();
					result.pop();
					v2=result.top();
					result.pop();
					for(k=0;k<v1.size();k++)
					{
						for(j=0;j<v2.size();j++)
						{
							if(v1[k]==v2[j])
							{
								v3.push_back(v1[j]);
							}
						}
					}
					result.push(v3);
					v3.clear();
				} 
				else if(sign_pop == '|')
				{
					v1=result.top();
					result.pop();
					v2=result.top();
					result.pop();
					v3=v1;
					for(j=0;j<v2.size();j++) v3.push_back(v2[j]);
					unique(v3.begin(),v3.end());
					result.push(v3);
					v3.clear();
				}
			}
			else
			{
				pn++;
			}
		}while(pn<strlen(str));
		//最后一步：已经没有括号
		{
			sign_pop=sign.top();
			sign.pop();
			if(sign_pop == ':') 
			{
				value = stk.top();
				stk.pop();
				attr_num = stk.top();
				stk.pop();
				temp=duanyan(Attr,attr_num,value);
				result.push(temp);
			}
			else if(sign_pop == '~')
			{
				value = stk.top();
				stk.pop();
				attr_num = stk.top();
				stk.pop();
				temp=fanduanyan(Attr,attr_num,value);
				result.push(temp);
			}
			else if(sign_pop == '&')
			{
				v2=result.top();
				result.pop();
				v1=result.top();
				result.pop();
				for(k=0;k<v1.size();k++)
				{
					for(j=0;j<v2.size();j++)
					{
						if(v1[k]==v2[j])
						{
							v3.push_back(v1[k]);
						}
					}
				}
				result.push(v3);
				v3.clear();
			} 
			else if(sign_pop == '|')
			{
				v2=result.top();
				result.pop();
				v1=result.top();
				result.pop();
				v3=v1;
				for(j=0;j<v2.size();j++) v3.push_back(v2[j]);
				unique(v3.begin(),v3.end());
				result.push(v3);
				v3.clear();
			}
		}
		//result中的结果放入最终结果容器中并清除result
		final_result.push_back(result.top());
		result.pop();
	}
	//输出结果
	for(i=0;i<final_result.size();i++)
	{
		if(final_result[i].size()==0) printf("\n");
		else
		{
			sort(final_result[i].begin(),final_result[i].end()); 
			for(j=0;j<final_result[i].size()-1;j++)
			{
				printf("%d ",final_result[i][j]);
			}
			printf("%d\n",final_result[i][j]);
		}
	} 
	return 0;
}
