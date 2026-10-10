#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n, k;
  int ans = 0;
  int curr = 0;
  priority_queue<pair<int, int>, vector<ii>, greater<ii>> pq;
  int in, out;
  cin >> n >> k;
  while (n--) {
    cin >> in >> out;
    pq.push({in, 1});
    pq.push({out + k + 1, 0});
  }
  while (!pq.empty()) {
    ii top = pq.top();
    pq.pop();
    if (top.second) {
      curr++;
      ans = max(ans, curr);
    } else {
      curr--;
    }
    // cerr << curr << ' ' << top.second << endl;
  }
  cout << ans << endl;

  return 0;
}