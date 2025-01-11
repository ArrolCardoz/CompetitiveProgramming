#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool isTrue = true;
  if (n % 2 == 1) {
    isTrue = false;
  }
  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    int m, n;
    cin >> m >> n;
    ans += n - m;
  }
  if (isTrue)
    cout << ans;
  else
    cout << "still running";
  return 0;
}