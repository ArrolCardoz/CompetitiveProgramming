#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &field, vector<vector<int>> &visited, int row,
         int col, int &count, bool &flowing, vector<int> dx, vector<int> dy) {
  //   cout << row << ' ' << col << endl;
  visited[row][col] = 1;
  for (int i = 0; i < 4; i++) {
    int r = row, c = col;
    r += dx[i];
    c += dy[i];
    if (r < field.size() && r > -1 && c < field[0].size() && c > -1 &&
        !visited[r][c] && field[r][c] <= field[row][col]) {
      if (field[r][c] == field[row][col]) {
        // cout << r << c << endl;
        count++;
        dfs(field, visited, r, c, count, flowing, dx, dy);
      } else {
        // cout << "TESTIING GGGGGGGGGGGGGGGGGG" << endl;
        flowing = true;
      }
    }
  }
}
int main() {
  int r, c;
  cin >> c >> r;
  vector<int> temp(c, 0);
  vector<vector<int>> visited(r, temp);
  vector<vector<int>> field(r, temp);
  map<int, vector<pair<int, int>>, std::greater<int>> maxHeight;
  vector<int> dx = {1, -1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int input;
      cin >> input;
      maxHeight[input].push_back(make_pair(i, j));
      field[i][j] = input;
    }
  }
  int ans = 0;
  for (auto &[height, group] : maxHeight) {
    for (auto &coords : group) {
      if (!visited[coords.first][coords.second]) {
        bool flowing = false;
        int count = 1;
        dfs(field, visited, coords.first, coords.second, count, flowing, dx,
            dy);
        if (!flowing) {
          //   cout << height << '=' << coords.first << ' ' << coords.second <<
          //   ' '
          //        << count << endl;

          ans += count;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}