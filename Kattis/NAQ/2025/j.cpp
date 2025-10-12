#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ans=10;
    vector<int>arr(10,10);
    // for(auto&it:arr)cout<<it<<endl;
    while(cin>>n){
 
        arr[n%10]--;
        // cout<<n%10<<' '<<n<<endl;
        if(arr[n%10]==0){
            ans--;
            // cout<<n<<' '<<ans<<endl;
            if(ans==1)
            {
                // for(auto&it:arr)cout<<it<<endl;
                for(int i=0;i<10;i++){
                   if(arr[i]>0)
                 { if(i==0)cout<<10<<endl;
                    else
                    cout<<(i)<<endl;
                  // cout<<i<<endl;
                   return 0;}
                }
            }
        }
    }
 
    return 0;
}