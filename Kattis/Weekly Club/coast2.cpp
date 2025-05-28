#include <bits/stdc++.h>
using namespace std;
void fillBorders(vector<vector<int>>& grid, vector<vector<int>>& visited,
                 int row, int col, vector<vector<int>>& coastValue) {
  //   cout << row << ' ' << col << endl;
  visited[row][col] = 1;
  int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
  int isLand = grid[row][col];
  int isLake = 1;
  for (int i = 0; i < 4; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    if (r > -1 && r < grid.size() && c > -1 && c < grid[0].size()) {
      if (isLand) {
        if (!visited[r][c] && grid[r][c])
          fillBorders(grid, visited, r, c, coastValue);
        else if (!grid[r][c]) {
          coastValue[r][c]++;
          //   cout << "TESTTTTT  " << coastValue[r][c] << ' ' << grid[r][c] <<
          //   endl;

          fillBorders(grid, visited, r, c, coastValue);
        }
      } else {
        if (r > -1 && r < grid.size() && c > -1 && c < grid[0].size())
          if (!grid[r][c])
            isLake = 0;
          else if (r == -1 || r == grid.size() || c == -1 ||
                   c == grid[0].size())
            isLake = 0;
      }
    }
  }
  if (!isLand && isLake) {
    // cout << row << ' ' << col << "IS LATEEEEEEE" << endl;
    coastValue[row][col]--;
  }
}
int main() {
  int row, col;
  cin >> row >> col;
  row += 2;
  col += 2;

  vector<vector<int>> coastValue(row, vector<int>(col, 0)),
      visited(row, vector<int>(col, 0)), grid(row, vector<int>(col, 0));
  string temp = "0";
  vector<int> tempRow(row, 0);

  // input
  grid[0] = tempRow;
  grid[row - 1] = tempRow;
  for (int i = 1; i < row - 1; i++) {
    for (int j = 0; j < col; j++) {
      if (j == 0 || j == col - 1) {
        grid[i][j] = 0;
        continue;
      }
      char input;
      cin >> input;
      grid[i][j] = input - '0';
    }
  }
  // process
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      //   cout << grid[i][j];
      if (grid[i][j] && !visited[i][j]) {
        fillBorders(grid, visited, i, j, coastValue);
      }
    }
    // cout << endl;
  }
  // add ans
  int ans = 0;
  for (auto& it : coastValue) {
    for (auto& a : it) {
      //   cout << a;
      ans += a;
    }
    // cout << endl;
  }
  cout << ans << endl;

  return 0;
}