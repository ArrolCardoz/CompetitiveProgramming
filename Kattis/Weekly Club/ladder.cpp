#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793;
int main() {
  double h, v;
  cin >> h >> v;
  v = v * PI / 180;
  int ans = ceil(h / sin(v));
  cout << ans << endl;
  return 0;
}