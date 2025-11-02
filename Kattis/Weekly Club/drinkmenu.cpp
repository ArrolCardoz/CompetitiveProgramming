#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,string>order;
    map<string,int>customer;
    int n,m;
    cin>>n>>m;
    cin.ignore();
    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);
        order[i]=str;
    }
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        customer[str]++;
        cout<<order[customer[str]]<<endl;
    }
    return 0;
}