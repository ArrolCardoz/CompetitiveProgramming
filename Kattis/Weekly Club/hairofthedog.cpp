#include <bits/stdc++.h>
using namespace std;

int main(){
	bool _isDrunk=false;
	int days,count=0;
	string str;
	cin>>days;
	while(days--)
	{
		cin>>str;
		if (str=="sober")
		{
			if (_isDrunk)
			{
				count++;
				_isDrunk=false;
			}
		}
		else {
			if (!_isDrunk)
				_isDrunk=true;
		}
	}
	cout<<count<<endl;

	
	
	return 0;
}