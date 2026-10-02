#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 40;
const int MAX_SUM = 400;
const int OFFSET = 400;
const int SIZE = 801;

int N;
int vectors[2][N_MAX];

int64_t memo[N_MAX + 1][SIZE][SIZE];

int64_t dp(int currX, int currY, int idx) {
  if (currX < -MAX_SUM || currX > MAX_SUM || currY < -MAX_SUM ||
      currY > MAX_SUM)
    return 0;

  if (idx == N) return currX == 0 && currY == 0;

  int x = currX + OFFSET;
  int y = currY + OFFSET;

  if (memo[idx][x][y] != -1) return memo[idx][x][y];

  int64_t ans = dp(currX, currY, idx + 1);

  ans += dp(currX + vectors[0][idx], currY + vectors[1][idx], idx + 1);

  return memo[idx][x][y] = ans;
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) cin >> vectors[0][i] >> vectors[1][i];

  memset(memo, -1, sizeof(memo));

  cout << dp(0, 0, 0) - 1 << '\n';
  return 0;
}