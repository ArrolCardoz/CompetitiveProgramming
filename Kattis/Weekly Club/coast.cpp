#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid, vector<vector<int>> &visitedTemp,
         vector<vector<int>> &visited, int &ans, int row, int col) {
  // cout << row << ' ' << col << ' ' << ans << endl;
  visited[row][col] = 1;
  visitedTemp[row][col] = 1;

  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  int isLand = grid[row][col];
  int isLake = 1;

  // check 4 sides
  for (int i = 0; i < 4; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    // cout << row << ' ' << col << '-' << r << ' ' << c << endl;
    if (isLand) {
      if (r > -1 && r < grid.size() && c > -1 && c < grid[0].size() &&
          !visitedTemp[r][c] && grid[r][c])
        dfs(grid, visitedTemp, visited, ans, r, c);

      else if (r > -1 && r < grid.size() && c > -1 && c < grid[0].size() &&
               !grid[r][c]) {
        // visited[r][c] = -1;
        // cout << r << ' ' << c << endl;
        ans++;
        dfs(grid, visitedTemp, visited, ans, r, c);  // check if lake
      } else if (r <= -1 || r >= grid.size() || c <= -1 ||
                 c >= grid[0].size()) {
        // visited[r][c] = -1;

        // cout << r << ' ' << c << endl;

        ans++;
        // cout << "CHECKKKKK " << r << ' ' << c << endl;
      }

    } else {
      // lake check
      // cout << ")";
      if ((r > -1 && r < grid.size() && c > -1 && c < grid[0].size() &&
           !grid[r][c]) ||
          (r <= -1 || r >= grid.size() || c <= -1 || c >= grid[0].size())) {
        isLake = 0;
        // cout << "TESTTTT" << r << ' ' << c << endl;
      }
    }
  }
  if (!isLand && isLake) {
    // cout << row << ' ' << col
    //      << " is a    lakeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee " << endl;
    ans--;
  }
  // if (isLand) visitedTemp[row][col] = 2;
  // else
  //   cout << row << ' ' << col << " is a not lake" << endl;
}

int main() {
  int r, c;
  cin >> r >> c;
  vector<int> temp(c, 0);
  vector<vector<int>> grid(r, temp), visited(r, temp);

  for (auto &row : grid) {
    for (auto &i : row) {
      char c;
      cin >> c;

      i = c - '0';
    }
  }
  int ans = 0;
  // cout << "TEST" << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      // cout << grid[i][j];
      if (grid[i][j] == 1 && !visited[i][j]) {
        vector<vector<int>> visitedTemp(r, temp);
        dfs(grid, visitedTemp, visited, ans, i, j);
        // cout << "ANS CHECK FIRST ISLAND-" << ans << endl;
        // for (auto &a : visitedTemp) {
        //   for (auto &b : a) cout << b;
        //   cout << endl;
        // }
      }
    }
    // cout << endl;
  }
  cout << ans << endl;
  return 0;
}