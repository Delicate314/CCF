#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	
	int n,a,b;  //分别表示西西艾弗岛上田地块数n和顿顿选定区域的右上角坐标(a,b)。
	int x1,x2,y1,y2; //表示一块田地的位置。(x1<x2,y1<y2)
	int sum=0;
	int x3,y3,x4,y4;
	scanf("%d %d %d",&n,&a,&b);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2); //x1<x2,y1<y2
		//左上 
		if(((x1>=0&&x1<=a)&&(y1>=0&&y1<=b)) || ((x2>=0&&x2<=a)&&(y2>=0&&y2<=b)) || ((x1>=0&&x1<=a)&&(y2>=0&&y2<=b)) || ((x2>=0&&x2<=a)&&(y1>=0&&y1<=b)))
		{
			x3=(x1>=0)?x1:0;
			y3=(y1>=0)?y1:0;
			x4=(x2<=a)?x2:a;
			y4=(y2<=b)?y2:b;
			sum+=(y4-y3)*(x4-x3);
		}
		
	}
	printf("%d",sum);
 } 
