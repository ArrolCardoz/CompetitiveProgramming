#include <bits/stdc++.h>
using namespace std;

void fillLand(int row, int col, vector<string>& grid, char change) {
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  //   cout << row << ' ' << col << endl;
  grid[row][col] = change;
  for (int i = 0; i < 4; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
      if (grid[r][c] == 'C') {
        // cout << r << ' ' << c << endl;

        grid[r][c] = change;
        fillLand(r, c, grid, change);
      }
    }
  }
}

void markLand(int row, int col, vector<string>& grid, char change) {
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  //   cout << "TeTSTINGSEgin" << row << ' ' << col << endl;
  grid[row][col] = change;
  for (int i = 0; i < 4; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    // cout << r << ' ' << c << endl;

    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
      if (grid[r][c] == 'L') {
        // cout << "         " << r << ' ' << c << endl;
        markLand(r, c, grid, change);
      }
    }
  }
}

void checkCloud(int row, int col, vector<string>& grid,
                vector<vector<bool>>& visited, bool& fillWater) {
  visited[row][col] = true;

  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  for (int i = 0; i < 4; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
        !visited[r][c]) {
      if (grid[r][c] == 'C') {
        checkCloud(r, c, grid, visited, fillWater);
      }
      if (grid[r][c] == 'L') {
        // cout << "tsetasetgseg" << endl;
        fillLand(row, col, grid, 'L');
        fillWater = false;
      }
    }
  }
  if (fillWater) fillLand(row, col, grid, 'W');
}

void processClouds(vector<string>& grid, vector<vector<bool>>& visited) {
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == 'C') {
        bool fillWater = false;
        checkCloud(i, j, grid, visited, fillWater);
      }
      //   cout << grid[i][j];
    }
    // cout << endl;
  }
}

int checkIslands(vector<string>& grid) {
  int ans = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      //   cout << grid[i][j];
      if (grid[i][j] == 'L') {
        markLand(i, j, grid, 'X');
        // cout << endl;
        // cout << endl;
        // cout << endl;

        // cout << i << ' ' << j << endl;
        ans++;
      }
      //   cout << endl;
    }
  }
  return ans;
}

int main() {
  int row, col;
  cin >> row >> col;
  vector<string> grid(row);
  vector<vector<bool>> visited(row, vector<bool>(col, false));
  for (int i = 0; i < row; i++) {
    cin >> grid[i];
  }
  processClouds(grid, visited);

  int ans = checkIslands(grid);
  cout << ans << endl;
  return 0;
}