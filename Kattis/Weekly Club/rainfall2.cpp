#include <bits/stdc++.h>
using namespace std;

int main() {
  double l, k, t1, t2, h;
  cin >> l >> k >> t1 >> t2 >> h;
  if (l > h)
    cout << fixed << setprecision(6) << h << ' ' << h;
  else if (l <= h) {
    cout << h << ' ';
    double ans = k * t2;
    cerr << k << ' ' << t2 << endl;
    cout << fixed << setprecision(6) << h + ans << endl;
  }
  return 0;
}