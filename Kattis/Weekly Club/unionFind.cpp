#include<bits/stdc++.h>
using namespace std;

class UnionFind
{
    struct UF { int p;int rank;};

    public:
    UnionFind(int n){
        howMany = n;
        uf = new UF[howMany];
        for(int i=0;i<howMany;i++){
            uf[i].p=i;
            uf[i].rank=0;
        }
    }
    ~UnionFind(){
        delete[] uf;
    }

    int find(int x){
        return find(uf,x);
    }

    bool merge(int x,int y){
        int res1, res2;
        res1 = find(uf,x);
        res2 = find(uf,y);
        if(res1!= res2){
            if(uf[res1].rank>uf[res2].rank){
                uf[res2].p=res1;
            }
            else {
                uf[res1].p=res2;
                if(uf[res1].rank== uf[res2].rank){
                    uf[res2].rank++;
                }
            }
            return true;
        }
        return false;
    }
    private:
    int howMany;
    UF* uf;

    int find(UF uf[],int x){
        if (uf[x].p!=x){
            uf[x].p=find(uf,uf[x].p);

        }
        return uf[x].p;
    }
};

int main(){
    int n,q;
    cin>>n>>q;
    UnionFind uf(n);
    while(q--){
        int a,b;
        
        char c;
        cin>>c>>a>>b;
        a--;
        b--;
        if(c=='?'){
            if(uf.find(a)==uf.find(b))cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        else {
              int a,b;
        
        char c;
        cin>>c>>a>>b;
        a--;
        b--;
        uf.merge(a,b);
        }
    }
    return 0;
}