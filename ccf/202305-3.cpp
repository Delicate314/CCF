#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Bite
{
	char str[3];
	bitset<8> bits;
	Bite(char str_in[3])
	{
		int p=0;
		int demical=0;
		int addition;
		strcpy(str,str_in);
		while(str[p]!='\0')
		{
			if(str[p]>='0' && str[p]<='9')
			{
				addition=int(str[p]-'0');
				demical=demical*16+addition;
				p++;
			}
			else if(str[p]>='a' && str[p]<= 'f')
			{
				addition=int(str[p]-'a'+10);
				demical=demical*16+addition;
				p++;
			}
		}
		bitset<8> temp(demical);
		bits=temp;
	}
	Bite()
	{
	}
};
int main()
{
	double s;
	double row;
	string str;
	int i,j,k,count=0,count_128,count_256;
	int pos,l=0,o;
	ll c,origin_l=0,l_temp,add_temp;
	int num=16;
	char Bite_16[3]={};
	char output_row[17]={};
	queue<struct Bite> input;
	vector<struct Bite> output;
	cin>>s;
	getchar();
	row=round(s/8+0.49);
	struct Bite guide,Bite_temp;
	bitset<8> temp;
	
	//输入 
	for(i=1;i<=row;i++)
	{
		getline(cin,str);
		if(i==row) num=str.length();
		for(j=0;j<=num-1;j=j+2)
		{
			Bite_16[0]=str[j];
			Bite_16[1]=str[j+1];
			input.push(Bite(Bite_16));
		}
	}
	//读 导引域
	count_128=0;
	do
	{
		guide=input.front();
		input.pop();
		//cout<<guide.bits<<endl;
		//cout<<guide.str<<endl;
		temp=guide.bits;
		temp.reset(7);
		c=(int)temp.to_ulong();
		for(i=0;i<count_128;i++) c=c*128;
		origin_l=origin_l+c;
		count_128++;
	}while(guide.bits.test(7));
	
	while(!input.empty())
	{
		//读  数据域 
		//取第 一个字节看类型
		struct Bite data=input.front();
		input.pop();
		o=0;
		//字面量 
		if((!data.bits.test(0)) && (!data.bits.test(1)))
		{
			bitset<8> length=data.bits>>2;
			l=(int)length.to_ulong();
			if(l<60)
			{
				l=l+1;
			}
			else
			{
				count_256=0;
				l_temp=0;
				for(i=1;i<=l-59;i++)
				{
					data=input.front();
					input.pop();
					add_temp=(int)data.bits.to_ulong();
					for(j=0;j<count_256;j++) add_temp=add_temp*256;
					l_temp+=add_temp;
					count_256++;
				}	
				l=l_temp+1;
			}
			for(i=1;i<=l;i++) 
			{
				output.push_back(input.front());
				input.pop();
			}
		}
		
		//回溯引用
		//首字节低两位为01 ,形式1 
		else if((data.bits.test(0)) && (!data.bits.test(1)))
		{
			bitset<8> length=data.bits>>2;
			if(length.test(3))
			{
				length.reset(3);
				o+=256;
			}
			if(length.test(4))
			{
				length.reset(4);
				o+=512;
			}
			if(length.test(5))
			{
				length.reset(5);
				o+=1024;
			}
			l=(int)length.to_ulong()+4;
			data=input.front();
			input.pop();
			o+=(int)data.bits.to_ulong();
		} 
		
		//首字节低两位为10，形式二 
		else if((!data.bits.test(0)) && (data.bits.test(1))) 
		{
			bitset<8> length=data.bits>>2;
			l=(int)length.to_ulong()+1;
			o=0;
			data=input.front();
			input.pop();
			o+=(int)data.bits.to_ulong();
			data=input.front();
			input.pop();
			o+=((int)data.bits.to_ulong())<<8;
		}
		//回溯引用(o,l) 
		if(o!=0)
		{
			pos=(int)output.size()-o;
			for(i=1;i<=l;i++)
			{
				output.push_back(output[pos]);
				pos++;
			}
		}		
	}
	
	//输出 
	while(!output.empty())
	{
		Bite_temp=output.front();
		output.erase(output.begin());
		strcat(output_row,Bite_temp.str);
		count++;
		if(count==8) 
		{
			cout<<output_row<<endl;
			memset(output_row,'\0',sizeof(output_row));
			count=0; 
		}
		 
	}
	cout<<output_row<<endl;
	return 0;
}
