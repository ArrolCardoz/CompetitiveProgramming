#include <bits/stdc++.h>
using namespace std;
void fillLake(vector<vector<int>>& grid, vector<vector<int>>& visited, int row,
              int col) {
  //   cout << "ETSTSDGSDGSEG " << row << ' ' << col << endl;
  visited[row][col] = 1;
  int isLand = grid[row][col];
  grid[row][col] = -1;
  int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
  for (int i = 0; i < 4; i++) {
    int r = row + dx[i];
    int c = col + dy[i];

    if (r > -1 && r < grid.size() && c > -1 && c < grid[0].size()) {
      if (!isLand) {
        // cout << r << ' ' << c << ' ' << grid[0].size() << endl;

        if (!visited[r][c] && grid[r][c] == 0) fillLake(grid, visited, r, c);
      }
    }
  }
}

void countCoast(vector<vector<int>>& grid, vector<vector<int>>& visited,
                int row, int col, int& ans) {
  visited[row][col] = 1;
  int isCoast = 0;
  int count = 0;
  int isLand = grid[row][col];
  int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
  for (int i = 0; i < 4; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    if (isLand) {
      if (grid[r][c] == -1) {
        isCoast = 1;
        count++;
      }
      if (!visited[r][c] && grid[r][c] > -1)
        countCoast(grid, visited, r, c, ans);
    }
  }
  if (isCoast) {
    // cout << row << ' ' << col << endl;
    ans += count;
  }
}

int main() {
  int row, col;
  cin >> row >> col;
  row += 2;
  col += 2;
  vector<int> temp(col, 0);
  vector<vector<int>> visited2(row, temp), visited(row, temp), grid(row, temp);
  vector<int> tempRow(row, 0);

  // input

  grid[row - 1] = tempRow;
  //   cout << grid[0].size();
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

  // pocess lake
  fillLake(grid, visited, 0, 0);

  int ans = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      //   cout << grid[i][j];
      if (grid[i][j] > -1 && !visited2[i][j]) {
        // cout << "NEW ISLAND" << endl;
        countCoast(grid, visited2, i, j, ans);
      }
    }
    // cout << endl;
  }
  cout << ans << endl;
  return 0;
}