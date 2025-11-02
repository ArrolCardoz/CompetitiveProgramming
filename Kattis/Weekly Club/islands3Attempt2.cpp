#include<bits/stdc++.h>
using namespace std;

const int dr[]={0,0,1,-1};
const int dc[]={1,-1,0,0};

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

int convert(int r1,int c1,int rowSize){
    return (rowSize*r1)+c1;
}
int main(){
    int row,col;
    cin>>row>>col;
    vector<string>grid(row);
    UnionFind uf(row*col);


    for(int i=0;i<row;i++)
    {
        string str;
        cin>>str;
        grid[i]=str;
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]=='L'||grid[i][j]=='C'){
                for(int k=0;k<4;k++){
                    // cerr<<i<< ' '<<j<<endl;
                    int newRow=i+dr[k];
                    int newCol=j+dc[k];

                    if(newRow>=0&&newRow<row&&
                       newCol>=0&&newCol<col&&
                       (grid[newRow][newCol]=='L'||grid[newRow][newCol]=='C'))
                       {
                        int p1=convert(i,j,col);
                        int p2=convert(newRow,newCol,col);
                        cerr<<p1<<' '<<p2<<endl;
                        uf.merge(p1,p2);
                       }


                }
            }
        }
    }
cerr<<"TEST"<<endl;
    set<int>s;
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]=='L'){
                int p=convert(i,j,col);
                s.insert(uf.find(p));
            }
        }}
        cout<<s.size()<<endl;
        return 0;

}