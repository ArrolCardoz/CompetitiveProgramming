#include <bits/stdc++.h>
using namespace std;
// its wrong

int main() {
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    else if (n == 1)
      cout << 0 << endl;
    else if (n == 2)
      cout << 1 << endl;
    else {
      int ans = ceil((-1 + sqrt(1 + (8.0 * n))) / 2);
      if (1LL * ans * (ans + 1) / 2 < n) ans++;  // round up if truncated
      cout << ans << endl;
      //   cout << ((-1 + sqrt(1 + (8.0 * n))) / 2) << endl;
    }
  }
  return 0;
}