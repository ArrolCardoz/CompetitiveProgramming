#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &input, int row, int col) {
  input[row][col] = '.';
  //   cout << row << ' ' << col << endl;
  int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
  int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

  for (int i = 0; i < 8; i++) {
    int r = row;
    int c = col;
    r += dx[i];
    c += dy[i];
    if (r < input.size() && r > -1 && c < input[0].size() && c > -1 &&
        input[r][c] == '#')
      dfs(input, r, c);
  }
}

int main() {
  int r, c;
  cin >> r >> c;
  vector<char> temp(c);
  vector<vector<char>> input(r, temp);
  for (auto &i : input) {
    for (auto &j : i) cin >> j;
  }
  int ans = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (input[i][j] == '#') {
        dfs(input, i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}