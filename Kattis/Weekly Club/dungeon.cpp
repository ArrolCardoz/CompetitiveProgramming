#include <bits/stdc++.h>
using namespace std;

void solution(int l, int r, int c) {
  int ans = 0;
  queue<tuple<int, int, int, int>> Queue;  // row,col,level,time
  vector<bool> temp1(c, false);
  vector<vector<bool>> temp2(r, temp1);
  vector<vector<vector<bool>>> visited(l, temp2);
  int dx[] = {0, 0, 1, -1, 0, 0};
  int dy[] = {1, -1, 0, 0, 0, 0};
  int dl[] = {0, 0, 0, 0, 1, -1};
  vector<string> str(r);

  vector<vector<string>> levels;

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < r; j++) {
      cin >> str[j];
      for (int k = 0; k < c; k++) {
        if (str[j][k] == 'S') {
          Queue.push(make_tuple(j, k, i, 0));
        }
      }
    }
    levels.push_back(str);
    str.clear();
    str.resize(r);
  }
  // bfs
  while (!Queue.empty()) {
    auto [row, col, lev, time] = Queue.front();
    Queue.pop();

    if (visited[lev][row][col]) continue;
    visited[lev][row][col] = true;

    if (levels[lev][row][col] == 'E') {
      if (time > 1)
        cout << "Escaped in " << time << " minute(s)." << endl;
      else
        cout << "Escaped in " << time << " minute." << endl;
      return;
    }
    for (int i = 0; i < 6; i++) {
      int newRow = row + dx[i];
      int newCol = col + dy[i];
      int newLev = lev + dl[i];

      // check
      if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c &&
          newLev >= 0 && newLev < l && levels[newLev][newRow][newCol] != '#') {
        Queue.push(make_tuple(newRow, newCol, newLev, time + 1));
      }
    }
  }
  cout << "Trapped!" << endl;
  return;
}
int main() {
  int l, r, c;
  cin >> l >> r >> c;
  while (l != 0 && r != 0 && c != 0) {
    solution(l, r, c);
    cin >> l >> r >> c;
  }
  return 0;
}