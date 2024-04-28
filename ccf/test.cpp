#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vec;
	int i;
	for(i=1;i<=10;i++) vec.push_back(i);
	for(i=1;i<=10;i++)
	{
		cout<<vec.front()<<endl;
		vec.erase(vec.begin());
	}
	return 0; 
}
