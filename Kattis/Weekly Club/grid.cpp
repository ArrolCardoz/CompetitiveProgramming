#include <bits/stdc++.h>
using namespace std;
// #define vii vector<vector<int>>
// #define pii pair<int,int>

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int r, c;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  cin >> r >> c;
  char str;
  vector<vector<int>> grid(r, vector<int>(c, 0)), visited(r, vector<int>(c, 0));
  for (auto& i : grid) {
    for (auto& j : i) {
      cin >> str;
      j = str - '0';
    }
  }

  queue<pair<int, int>> q;
  q.push({0, 0});
  bool ok = false;
  while (!q.empty()) {
    auto [row, col] = q.front();
    q.pop();
    if (row == r - 1 && col == c - 1) {
      cout << visited[row][col] << endl;
      ok = true;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int newR = row + (dr[i] * grid[row][col]);
      int newC = col + (dc[i] * grid[row][col]);
      if (newR < 0 || newR >= r) continue;
      if (newC < 0 || newC >= c) continue;
      if (visited[newR][newC] != 0) continue;

      q.push({newR, newC});
      visited[newR][newC] = visited[row][col] + 1;
    }
  }

  if (!ok) cout << -1 << endl;

  return 0;
}