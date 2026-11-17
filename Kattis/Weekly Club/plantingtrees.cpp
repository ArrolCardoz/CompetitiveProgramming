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
    priority_queue<int>pq;
    while(n--){
        int i;
        cin>>i;
        pq.push(i);
    }
    int ans=-1,ctr=1;
    while(!pq.empty()){
        int curr=pq.top();
        pq.pop();
        ans=max(ctr+1+curr,ans);
        ctr++;
    }
    cout<<ans<<endl;
    return 0;
}