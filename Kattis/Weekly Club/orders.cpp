#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 105;
const int MAX_W = 30001;

int memo[MAX_N][MAX_W];
int p[MAX_N][MAX_W];
int A[MAX_N];
int n;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int dp(int idx, int remW) {
  if (remW == 0) return 1;
  if (idx == n) return 0;
  int& ans = memo[idx][remW];
  if (ans != -1) return ans;
  ans = dp(idx + 1, remW);
  if (ans) p[idx][remW] = 0;
  if (A[idx] <= remW) {
    int take = dp(idx, remW - A[idx]);
    ans += take;
    if (take) p[idx][remW] = 1;
  }
  return ans = min(ans, 2);
}

void solution() {
  int c;
  cin >> c;

  int ans = dp(0, c);
  // cerr << ans << endl;
  if (ans == 0)
    cout << "Impossible" << endl;
  else if (ans > 1)
    cout << "Ambiguous" << endl;
  else {
    int s = c;

    bool first = false;

    for (int i = 0; i < n && s > 0; i++) {
      if (p[i][s] == 1) {
        if (first) cout << ' ';
        cout << i + 1;
        s -= A[i];
        i--;
        first = true;
      }
    }
  }
  cout << endl;
}
int main() {
  fastIO();
  memset(memo, -1, sizeof(memo));
  memset(p, -1, sizeof(p));

  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  int m;
  cin >> m;
  while (m--) {
    solution();
  }
  return 0;
}