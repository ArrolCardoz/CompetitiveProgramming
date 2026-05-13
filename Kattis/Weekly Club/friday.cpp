#include <bits/stdc++.h>
using namespace std;

void solution() {
  int d, m;
  int ans = 0;
  cin >> d >> m;
  int total = 0;
  while (m--) {
    int i;
    cin >> i;

    if (i >= 13) {
      i -= 13;
      total += 13;
      //   cerr << total % 7 << endl;
      if (total % 7 == 6) ans++;
    }
    total += i;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
}