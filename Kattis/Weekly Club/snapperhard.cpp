#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  int ctr = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int bitmask = (1 << n) - 1;
    // cout << bitmask << endl;
    cout << "Case #" << ctr << ": ";
    ctr++;
    if (bitmask == (bitmask & k))
      cout << "ON" << endl;
    else
      cout << "OFF" << endl;
  }
  return 0;
}