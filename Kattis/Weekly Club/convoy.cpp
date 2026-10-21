#include <bits/stdc++.h>
using namespace std;
#define pii tuple<int64_t, int64_t, int64_t>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n, k;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  cin >> n >> k;
  vector<int64_t> num(n);
  vector<int64_t> times(n, 0);

  for (auto& it : num) cin >> it;

  sort(num.begin(), num.end());

  for (int64_t i = 0; i < min(k, n); i++) {
    pq.push({num[i], i, 0LL});
    times[i]++;
  }

  int64_t ans = 0;
  int total = n;

  while (total > 0) {
    auto [t, idx, pos] = pq.top();
    // cerr << t << ' ' << pos << endl;
    pq.pop();
    while (k == 0 && pos == 0) {
      auto [t, idx, pos] = pq.top();
      pq.pop();
    }
    if (pos) {
      total -= min(total, 4);
      ans = t;
      times[idx] += 2;
      pq.push({num[idx] * (times[idx]), idx, 1});
    } else {
      total -= min(total, 5);
      ans = t;
      times[idx] += 2;
      pq.push({num[idx] * (times[idx]), idx, 1});
      k--;
    }
    // cerr << total << ' ' << idx << ' ' << t << ' ' << ans << endl;
  }
  cout << ans << endl;

  return 0;
}