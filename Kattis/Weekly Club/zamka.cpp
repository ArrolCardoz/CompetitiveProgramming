#include <bits/stdc++.h>
using namespace std;


int sumDigits(int n){
    int ans=0;
    string str = to_string(n);
    for(auto &it:str){
        ans += it - '0';

    }

    return ans;
}

int main(){
    int l,d,x;
    cin>>l>>d>>x;

    for(int i=l;i<=d;i++){
        if (sumDigits(i)==x){cout<<i<<endl;break;}
        
    }
    for(int i=d;i>=l;i--){
        if (sumDigits(i)==x){cout<<i<<endl;break;}
        
    }
    return 0;
}