#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>>& treasureMap, vector<vector<int>>& visited,
         int row, int column, int& ans, vector<int>& dx, vector<int>& dy) {
  visited[row][column] = 1;
  if (treasureMap[row][column] == 'G') {
    ans++;
    // cout << r << ' ' << c << "===============" << endl;
  }
  //   cout << row << ' ' << column << endl;
  //   for (auto& r : visited) {
  //     for (auto& c : r) cout << c << ' ';
  //     cout << endl;
  //   }
  //   cout << endl;

  bool check = true;

  for (int i = 0; i < 4; i++) {
    int r = row;
    int c = column;
    r += dx[i];
    c += dy[i];
    if (r < treasureMap.size() && r > -1 && c < treasureMap[0].size() &&
        c > -1 && treasureMap[r][c] != '#') {
      if (treasureMap[r][c] == 'T') {
        return;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    int r = row;
    int c = column;
    r += dx[i];
    c += dy[i];
    if (r < treasureMap.size() && r > -1 && c < treasureMap[0].size() &&
        c > -1 && !visited[r][c] && treasureMap[r][c] != '#') {
      dfs(treasureMap, visited, r, c, ans, dx, dy);
    }
  }
}

int main() {
  int column, row;
  cin >> column >> row;
  vector<char> temp(column, '.');
  vector<vector<char>> treasureMap(row, temp);
  vector<int> temp2(column, 0);
  vector<vector<int>> visited(row, temp2);
  pair<int, int> player;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      char input;
      cin >> input;
      treasureMap[i][j] = input;
      if (input == 'P') player = make_pair(i, j);
    }
  }
  int ans = 0;
  vector<int> dx = {0, 0, 1, -1};
  vector<int> dy = {1, -1, 0, 0};

  dfs(treasureMap, visited, player.first, player.second, ans, dx, dy);
  cout << ans << endl;
  return 0;
}