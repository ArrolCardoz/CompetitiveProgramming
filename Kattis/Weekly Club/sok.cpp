#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, i, j, k;
  cin >> a >> b >> c >> i >> j >> k;
  double minRatio = INT_MAX;
  minRatio = min(a / i, minRatio);
  minRatio = min(b / j, minRatio);
  minRatio = min(c / k, minRatio);
  cout << fixed << setprecision(6) << a - (i * minRatio) << ' ' << fixed
       << setprecision(6) << b - (j * minRatio) << ' ' << fixed
       << setprecision(6) << c - (k * minRatio) << ' ' << endl;
  return 0;
}