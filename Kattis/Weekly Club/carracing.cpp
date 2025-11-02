#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    unordered_map<int,vector<int>>avg;
    cin>>n;
    int maxAvg=INT_MAX;
    int carNum=0;
    while(n--){
        int car,pos;
        cin>>car>>pos;
        avg[car].push_back(pos);
    }
    for(auto& [car,pos]:avg){
        int sum=0;
        for(auto p:pos)sum+=p;
        sum=sum/pos.size();
        if(maxAvg>sum)
            {
                carNum=car;
                maxAvg=sum;
            }
    }
    cout<<carNum<<endl<<maxAvg<<endl;
    return 0;

}