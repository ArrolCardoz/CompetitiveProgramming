#include <bits/stdc++.h>
using namespace std;
#define ii pair<int64_t, int64_t>
#define vii vector<ii>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n, m;
  int64_t ans = 0;
  cin >> n >> m;
  vector<int64_t> f(n);
  vii mong(m);
  for (auto& it : f) cin >> it;
  for (auto& [a, b] : mong) {
    cin >> b >> a;
  }

  sort(f.begin(), f.end());
  sort(mong.begin(), mong.end(), greater<ii>());
  for (auto& [cost, fishNum] : mong) {
    if (n < 0) break;
    int num = min(int64_t(n), fishNum);
    while (num--) {
      ans += cost * f[n - 1];
      cerr << ans << endl;
      n--;
    }
  }
  cout << ans << endl;
  return 0;
}