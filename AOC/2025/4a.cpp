#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1, -1, 1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

void count(vector<string>& grid, int row, int col, int& ans,
           vector<vector<bool>>& visited) {
  //   cout << row << ' ' << col << endl;
  int adjRolls = 0;
  visited[row][col] = true;

  // check
  for (int i = 0; i < 8; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
        (grid[r][c] == '@' || grid[r][c] == 'X')) {
      adjRolls++;
    }
  }
  if (adjRolls < 4 && grid[row][col] == '@') {
    ans++;
    grid[row][col] = 'X';
  }

  if (row + 1 < grid.size() && !visited[row + 1][col])
    count(grid, row + 1, col, ans, visited);
  if (col + 1 < grid[0].size() && !visited[row][col + 1])
    count(grid, row, col + 1, ans, visited);
}

int main() {
  vector<string> grid;
  string str;

  while (getline(cin, str)) {
    if (str == "q") break;
    grid.push_back(str);
  }
  vector<vector<bool>> visited(grid.size(),
                               vector<bool>(grid[0].size(), false));
  int ans = 0;
  count(grid, 0, 0, ans, visited);

  cout << ans << endl;
  //   for (auto& it : grid) cout << it << endl;

  return 0;
}