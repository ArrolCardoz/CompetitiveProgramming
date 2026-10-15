#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n, m;
  cin >> n >> m;

  vector<vector<int>> valid(n, vector<int>(n, 1));
  vector<int> bad(1 << n, 0);
  int a, b;

  while (m--) {
    cin >> a >> b;
    a--;
    b--;
    bad[a] |= (1 << b);
    bad[b] |= (1 << a);
  }

  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    int mask = i;
    bool ok = true;
    while (mask) {
      int two_pow_j = LSOne(mask);
      int j = __builtin_ctz(two_pow_j);
      mask -= two_pow_j;

      j = bad[j] & i;
      if (__builtin_popcount(j) > 0) {
        // cerr << i << endl;
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  }
  cout << ans << endl;

  return 0;
}