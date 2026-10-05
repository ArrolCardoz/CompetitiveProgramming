#include <bits/stdc++.h>
using namespace std;

int p[105][105];

int query(int r1, int c1, int r2, int c2) {
  return p[r2][c2] - p[r1 - 1][c2] - p[r2][c1 - 1] + p[r1 - 1][c1 - 1];
}

void print(int ansR, int ansC, int K, int maxFlies,
           const vector<string>& grid) {
  ansR--;
  ansC--;

  int endR = ansR + K - 1;
  int endC = ansC + K - 1;

  cout << maxFlies << endl;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (((i == ansR || i == endR) && (j == ansC || j == endC))) {
        cout << "+";
      } else if ((i == ansR || i == endR) && (j > ansC && j < endC)) {
        cout << "-";
      } else if ((j == ansC || j == endC) && (i > ansR && i < endR)) {
        cout << "|";
      } else {
        cout << grid[i][j];
      }
    }
    cout << endl;
  }
}

int main() {
  int R, S, K;
  cin >> R >> S >> K;

  vector<string> grid(R);
  for (auto& it : grid) cin >> it;

  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= S; j++) {
      int val = (grid[i - 1][j - 1] == '*') ? 1 : 0;
      p[i][j] = val + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    }
  }

  int maxFlies = -1, bestR = 0, bestC = 0;
  for (int i = 1; i <= R - K + 1; i++) {
    for (int j = 1; j <= S - K + 1; j++) {
      int flies = query(i + 1, j + 1, i + K - 2, j + K - 2);
      if (flies > maxFlies) {
        maxFlies = flies;
        bestR = i;
        bestC = j;
      }
    }
  }
  print(bestR, bestC, K, maxFlies, grid);

  return 0;
}