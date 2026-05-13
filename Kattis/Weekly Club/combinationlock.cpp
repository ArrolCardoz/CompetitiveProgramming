#include <bits/stdc++.h>
using namespace std;

int main() {
  int start, n1, n2, n3;
  while (cin >> start >> n1 >> n2 >> n3 && (start || n1 || n2 || n3)) {
    int ans = 1080;
    ans += ((start + (40 - n1)) % 40) * 9;
    ans += ((n2 + (40 - n1)) % 40) * 9;
    ans += ((n2 + (40 - n3)) % 40) * 9;
    cout << ans << endl;
  }
  return 0;
}
