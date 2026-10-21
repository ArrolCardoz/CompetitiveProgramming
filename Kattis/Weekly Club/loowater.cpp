#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

bool solution() {
  int n, m, input, ans = 0;
  cin >> n >> m;
  if (n == 0 && m == 0) return false;

  priority_queue<int, vector<int>, greater<int>> d, k;
  for (int i = 0; i < n; i++) {
    cin >> input;
    d.push(input);
  }
  for (int i = 0; i < m; i++) {
    cin >> input;
    k.push(input);
  }
  while (!d.empty() && !k.empty()) {
    int D = d.top(), K = k.top();
    if (K >= D) {
      ans += K;
      d.pop();
    }
    k.pop();
  }
  if (d.empty())
    cout << ans << endl;
  else
    cout << "Loowater is doomed!" << endl;
  return true;
}
int main() {
  fastIO();
  while (solution());
  return 0;
}