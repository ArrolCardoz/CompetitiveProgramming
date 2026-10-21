#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int s, c, k;
  cin >> s >> c >> k;
  vector<int> A(s);
  for (auto& it : A) cin >> it;
  sort(A.begin(), A.end());
  int curr = A[0], ctr = 0, ans = 1;
  for (auto& it : A) {
    if ((it - curr) <= k && ctr < c) {
      ctr++;
      continue;
    } else {
      ans++;
      curr = it;
      ctr = 1;
    }
  }
  cout << ans << endl;
  return 0;
}