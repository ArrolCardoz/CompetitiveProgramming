#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int current;
    cin >> current;
    int next, ans = 0;
    while (cin >> next) {
      if (next == 0) break;
      if (next > current * 2) {
        ans += next - (current * 2);
      }
      current = next;
    }
    cout << ans << endl;
  }
  return 0;
}