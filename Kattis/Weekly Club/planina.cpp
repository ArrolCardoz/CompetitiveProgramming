#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 2;
  for (int i = 0; i < n; i++) {
    ans += ans - 1;
  }
  cout << ans * ans << endl;
  return 0;
}