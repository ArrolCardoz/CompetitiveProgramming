#include <bits/stdc++.h>
using namespace std;

void solution() {
  int minimalRadius, points;
  cin >> minimalRadius >> points;
  int x1, y1, i1, i2, p1, p2;
  double perimeter = 0;
  // get the first point
  cin >> x1 >> y1;
  p1 = x1;
  p2 = y1;
  points--;
  while (points--) {
    cin >> i1 >> i2;
    perimeter += sqrt(((i1 - p1) * (i1 - p1)) + ((i2 - p2) * (i2 - p2)));
    p1 = i1;
    p2 = i2;
  }
  perimeter += sqrt(((x1 - p1) * (x1 - p1)) + ((y1 - p2) * (y1 - p2)));

  // formula
  double ans = 1 - (minimalRadius * M_PI * 2) / perimeter;
  if (ans <= 0)
    cout << "Not possible" << endl;
  else
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}