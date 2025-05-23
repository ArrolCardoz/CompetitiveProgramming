#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int p, r, f;
    cin >> p >> r >> f;
    int ans = 0;
    while (p <= f) {
      cout << p << endl;
      p += r * p;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
