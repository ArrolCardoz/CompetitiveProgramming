#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
while(n!=-1){
int previousTime=0;
int ans=0;
for(int i=0;i<n;i++){
int miles,hours;
cin>>miles>>hours;
ans+=miles*(hours-previousTime);
previousTime=hours;
}
cout<<ans<<" miles"<<endl;
cin>>n;
}
return 0;
}
