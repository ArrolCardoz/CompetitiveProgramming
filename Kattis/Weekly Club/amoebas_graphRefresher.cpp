#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<string>& graph,
         vector<vector<bool>>& visited) {
  visited[row][col] = true;
  vector<int> dx = {1, -1, 0, 0, 1, 1, -1, -1};
  vector<int> dy = {0, 0, 1, -1, 1, -1, -1, 1};
  for (int i = 0; i < 8; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    // cout << i << r << ' ' << c << endl;
    if (r < visited.size() && r >= 0 && c < visited[0].size() && c >= 0 &&
        graph[r][c] == '#' && !visited[r][c]) {
      dfs(r, c, graph, visited);
    }
  }
}

int main() {
  int row, col;
  cin >> row >> col;
  vector<vector<bool>> visited(row, vector<bool>(col, false));
  vector<string> graph(row);
  int ans = 0;
  for (int i = 0; i < row; i++) {
    cin >> graph[i];
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (graph[i][j] == '#' && !visited[i][j]) {
        ans++;
        // for (int r = 0; r < row; r++) {
        //   for (int c = 0; c < col; c++) {
        //     cout << visited[r][c];
        //   }
        //   cout << endl;
        // }
        // cout << graph[i][j] << endl;
        // cout << i << ' ' << j << endl;
        dfs(i, j, graph, visited);
      }
    }
  }
  cout << ans;

  return 0;
}