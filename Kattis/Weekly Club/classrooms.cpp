#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n, k, ans = 0;
  cin >> n >> k;
  vector<pii> num(n);
  multiset<int> a;
  for (auto& [e, s] : num) cin >> s >> e;
  for (int i = 0; i < k; i++) a.insert(0);
  sort(num.begin(), num.end());
  for (auto& [e, s] : num) {
    auto it = a.lower_bound(s);
    if (it == a.begin()) continue;
    it--;
    a.erase(it);
    a.insert(e);
    ans++;
  }
  cout << ans << endl;
  return 0;
}