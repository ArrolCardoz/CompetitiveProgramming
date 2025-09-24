#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int time[3];
  for (int i = 0; i < 3; i++) {
    int n;
    cin >> n;
    time[i] = --n;
  }
  for (int i = 0; i < 3; i++) {
    int n = time[i];
    // cout << (n % (x1 + y1) + 1) << ' ' << (n % (x2 + y2)) + 1 << endl;
    if ((n % (x1 + y1) + 1) > x1 && (n % (x2 + y2)) + 1 > x2)
      cout << "none" << endl;
    else if (n % (x1 + y1) + 1 > x1 || (n % (x2 + y2)) + 1 > x2)
      cout << "one" << endl;
    else
      cout << "both" << endl;
  }
  return 0;
}