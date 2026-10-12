#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n = 5, ans = 0, idx = 0;
  for (int j = 1; j <= n; j++) {
    int temp = 0;
    for (int i = 0; i < 4; i++) {
      int a;
      cin >> a;
      temp += a;
    }
    if (temp > ans) {
      ans = temp;
      idx = j;
    }
  }
  cout << idx << ' ' << ans << endl;
  return 0;
}