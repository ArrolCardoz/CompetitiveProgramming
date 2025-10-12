#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b;
    int r1,g1,b1;
    int rg,gb;
    int ans=0;
    cin>>r>>g>>b;
    cin>>r1>>g1>>b1;
    cin>>rg>>gb;
    if(r1<r){
        rg-=(r-r1);
        ans+=(r-r1);
        if(rg<0){cout<<-1<<endl; return 0;}
   

    }
    // cout<<ans<<endl;
    if(b1<b){
        gb-=(b-b1);
        ans+=(b-b1);
        if(gb<0){cout<<-1<<endl; return 0;}

    }
    int totalG=rg+gb;
    // cout<<ans<<endl;

    if(g1<g){
        totalG-=(g-g1);
        ans+=(g-g1);
        if(totalG<0){cout<<-1<<endl; return 0;}

    }
    // cout<<ans<<endl;

    // if((totalG-g1)<0)cout<<-1<<endl;
     cout<<ans<<endl;
    return 0;
}