#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto& it : h) cin >> it;
  sort(h.begin(), h.end());
  double ans = 2.0;
  for (int i = 0; i < n; i++) {
    if ((i + 1) < h[i]) {
      cout << "impossible" << endl;
      return 0;
    }
    ans = min(ans, (double)h[i] / (i + 1));
  }
  cout << setprecision(10) << ans << endl;
  return 0;
}