#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    ll l[3], w[3];
    for (int i = 0; i < 3; i++) cin >> l[i] >> w[i];

    ll best = LLONG_MAX;
    for (int mask = 0; mask < 8; mask++) {
      ll a[3], b[3];
      for (int i = 0; i < 3; i++) {
        if ((mask >> i) & 1) {
          a[i] = w[i];
          b[i] = l[i];
        }  // rotated
        else {
          a[i] = l[i];
          b[i] = w[i];
        }
      }

      // Layout 1: all three in a row
      best = min(best, (a[0] + a[1] + a[2]) * max({b[0], b[1], b[2]}));

      // Layout 2: building 'lone' beside a stack of the other two
      for (int lone = 0; lone < 3; lone++) {
        int j = (lone + 1) % 3, k = (lone + 2) % 3;
        ll W = a[lone] + max(a[j], a[k]);
        ll H = max(b[lone], b[j] + b[k]);
        best = min(best, W * H);
      }
    }
    cout << best << "\n";
  }
  return 0;
}