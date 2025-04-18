#include <bits/stdc++.h>
using namespace std;

int main(){
	int current,correct;
	cin>>current>>correct;
	if(current>correct)correct+=360;
	int clockwise = correct-current;
	if(clockwise<=abs(clockwise-360))
		cout<<clockwise<<endl;
	else cout<<clockwise-360<<endl;
	return 0;
}