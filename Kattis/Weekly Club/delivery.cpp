#include <bits/stdc++.h>
using namespace std;
#define pii pair<int64_t, int64_t>
int64_t n, k;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solution(priority_queue<pii>& PQ, int64_t& ans) {
  while (!PQ.empty()) {
    auto [dest, letters] = PQ.top();
    cerr << dest << ' ' << letters << endl;
    PQ.pop();
    ans += dest * 2 * ((letters + (k - 1)) / k);
    int64_t remaining = 0;
    if (letters % k) remaining = k - (letters % k);

    while ((remaining > 0) && !PQ.empty()) {
      auto [topD, topL] = PQ.top();
      PQ.pop();
      if (topL - remaining > 0) {
        topL -= remaining;
        // cerr << topL << '-' << remaining << endl;
        remaining = 0;
        PQ.push({topD, topL});
      } else
        remaining -= topL;
    }
  }
}
int main() {
  fastIO();
  int64_t destination, num;
  cin >> n >> k;
  priority_queue<pii> maxPQ, minPQ;
  while (n--) {
    cin >> destination >> num;
    if (destination > 0)
      maxPQ.push({destination, num});
    else
      minPQ.push({-destination, num});
  }
  int64_t ans = 0;

  solution(minPQ, ans);
  solution(maxPQ, ans);

  cout << ans << endl;
  return 0;
}