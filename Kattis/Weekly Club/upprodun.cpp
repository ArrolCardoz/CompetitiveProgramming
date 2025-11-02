#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string>ans(n);
   for(int i=0;i<m;i++){
    ans[i%n]+=("* ");
   }
   for(auto &it:ans){cout<<it<<endl;}
   return 0;
}