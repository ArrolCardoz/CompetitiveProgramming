#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5005;
const int MAX_W = 1005;
int W[MAX_N];
int H[MAX_N];
int memo[MAX_N][MAX_W];
int n, c;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int dp(int idx, int remW, int currMaxH) {
  if (idx == n) return currMaxH;  // base case

  int& ans = memo[idx][remW];
  if (ans != -1) return ans;

  if (remW - W[idx] < 0)  // if cannot fit in current row
    return ans = dp(idx + 1, c - W[idx], H[idx]) + currMaxH;

  return ans =
             min(dp(idx + 1, remW - W[idx], max(currMaxH, H[idx])),
                 dp(idx + 1, c - W[idx], H[idx]) + currMaxH);  // else try both
}

int main() {
  fastIO();
  memset(memo, -1, sizeof(memo));
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> W[i] >> H[i];
  cout << dp(0, c, H[0]);

  return 0;
}