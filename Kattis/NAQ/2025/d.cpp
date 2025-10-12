#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>&gird,vector<vector<unordered_set<int>>>&visited,int destX,int destY,int x,int y,int direction,int counter)
{   
    // cout<<x<<' '<<y<<' '<<direction<<endl;
    if (destX==x&&destY==y)return true;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    if( visited[x][y].size()==4||visited[x][y].find(direction)!=visited[x][y].end())return false;
    visited[x][y].insert(direction);
    //case 1
    int newX=dx[(direction+3)%4]+x;
    int newY=dy[(direction+3)%4]+y;
    int case2X=dx[(direction)%4]+x;
    int case2Y=dy[(direction)%4]+y;
    if(newX>=0&&newX<visited.size()&&newY>=0&&newY<visited[0].size()&&!gird[newX][newY])
       return dfs(gird,visited,destX,destY,newX,newY,(direction+3)%4,0);
    else if(case2X>=0&&case2X<visited.size()&&case2Y>=0&&case2Y<visited[0].size()&&!gird[case2X][case2Y])
       return dfs(gird,visited,destX,destY,case2X,case2Y,direction,0);
    else
       return dfs(gird,visited,destX,destY,x,y,(direction+1)%4,counter+1);



}

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>grid(r,vector<int>(c));
    vector<vector<unordered_set<int>>>visited(r,vector<unordered_set<int>>(c));
    int xStart,yStart;
    int xEnd,yEnd;
    cin>>xStart>>yStart>>xEnd>>yEnd;
    xStart--;
    yStart--;
    xEnd--;
    yEnd--;
    // cout<<grid.size()<<' '<<grid[0].size()<<endl;
    for(int i=0;i<r;i++)
    {
        string str;
        cin>>str;
        for(int j=0;j<c;j++){
            
            grid[i][j]=str[j]-'0';
            // cout<<str[j]-'0'<<' ';
        }
        // cout<<endl;
    }

    if(dfs(grid,visited,xEnd,yEnd,xStart,yStart,0,0))cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}