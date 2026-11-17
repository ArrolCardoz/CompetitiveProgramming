#include<bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main(){
    fastIO();
    int n;
    cin>>n;
    vector<int>v(n);
    int ans=0;
    for(auto&it:v){
        cin>>it;
   
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<n/2;i++){
        ans+=v[i];
    }
     for(int i=n/2;i<n;i++){
        ans+=v[i]/2;
    }

    
    cout<<ans<<endl;
    return 0;
}