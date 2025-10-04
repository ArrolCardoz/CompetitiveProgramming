#include <bits/stdc++.h>
using namespace std;

int main() {
  double bookx, booky, x, y;
  bool light = false;
  int n;
  cin >> n;
  while (n--) {
    // cout << "test2" << endl;

    light = false;
    cin >> bookx >> booky;
    int n1;
    cin >> n1;
    while (n1--) {
      //   cout << (16 * 16) << '>' << (x * x) + (y * y) << endl;
      cin >> x >> y;
      double dx = x - bookx;
      double dy = y - booky;
      if ((dx * dx) + (dy * dy) <= (16.0 * 16.0)) {
        light = true;
      }
    }
    if (light)
      cout << "light a candle" << endl;
    else
      cout << "curse the darkness" << endl;
  }
  return 0;
}