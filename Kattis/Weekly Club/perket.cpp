#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n;
  cin >> n;
  int ans = 127 * 100 * 100;
  vector<int> sour(n), bitter(n);

  for (int i = 0; i < n; i++) {
    cin >> sour[i] >> bitter[i];
  }

  for (int i = 1; i < (1 << n); i++) {
    int sourTotal = 0;
    int bitterTotal = 0;
    int mask = i;
    while (mask) {
      int two_pow_j = LSOne(mask);
      int j = __builtin_ctz(two_pow_j);
      mask -= two_pow_j;
      if (sourTotal == 0)
        sourTotal = sour[j];
      else
        sourTotal *= sour[j];
      bitterTotal += bitter[j];
      ans = min(ans, abs(sourTotal - bitterTotal));
    }
  }
  cout << ans << endl;
  return 0;
}