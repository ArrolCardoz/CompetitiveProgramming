#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    map<int,int>diff;
    while(n--){
        int i;
        cin>>i;
        diff[i]++;
    }
    int ans=diff.size();
    if(ans<k)cout<<ans<<endl;
    else cout<<k<<endl;
    return 0;
}