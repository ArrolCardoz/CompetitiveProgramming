#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a;
  int ans = 0;
  while (n--) {
    cin >> a;
    if (a < 0) ans += a;
  }
  ans *= -1;
  cout << ans << endl;
  return 0;
}