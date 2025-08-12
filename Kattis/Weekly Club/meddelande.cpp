#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<string>& grid,
         vector<vector<string>>& visited, string currentStr) {
  //   cout << currentStr << " ";
  if (currentStr.size() < visited[row][col].size()) return;
  visited[row][col] = currentStr;

  int dx[] = {1, 0};
  int dy[] = {0, 1};
  for (int i = 0; i < 2; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    if (r < grid.size() && c < grid[0].size()) {
      string str = currentStr;
      if (grid[r][c] != '.') {
        str = currentStr + grid[r][c];
        // cout << currentStr << " " << str << endl;
      }
      dfs(r, c, grid, visited, str);
    }
  }
}
int main() {
  int row, col;
  cin >> row >> col;
  vector<string> grid(row);
  vector<vector<string>> visited(row, vector<string>(col, ""));
  for (int i = 0; i < row; i++) {
    // cout << i << endl;
    string str;
    cin >> str;
    grid[i] = str;
  }
  string start = "";
  if (grid[0][0] != '.') start += grid[0][0];

  //   cout << "START" << start << endl;
  dfs(0, 0, grid, visited, start);
  cout << visited[row - 1][col - 1] << endl;
  //   cout << visited[row][col].size() << endl;
  //   cout << "TEST" << endl;

  return 0;
}