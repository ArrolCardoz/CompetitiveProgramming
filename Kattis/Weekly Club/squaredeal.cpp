#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h[3], w[3];
  for (int i = 0; i < 3; i++) cin >> h[i] >> w[i];

  int p[3] = {0, 1, 2};
  do {
    for (int mask = 0; mask < 8; mask++) {
      int H[3], W[3];
      for (int k = 0; k < 3; k++) {
        int i = p[k];
        if ((mask >> k) & 1) {
          H[k] = w[i];
          W[k] = h[i];
        } else {
          H[k] = h[i];
          W[k] = w[i];
        }
      }

      if (H[0] == H[1] && H[1] == H[2] && W[0] + W[1] + W[2] == H[0]) {
        cout << "YES\n";
        return 0;
      }

      if (H[1] == H[2] && W[1] + W[2] == W[0] && H[0] + H[1] == W[0]) {
        cout << "YES\n";
        return 0;
      }
    }
  } while (next_permutation(p, p + 3));

  cout << "NO\n";
  return 0;
}