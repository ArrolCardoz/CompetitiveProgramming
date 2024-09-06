#include <bits/stdc++.h>
using namespace std;

void solution() {
  int x1, x2, y1, y2;
  int a1, a2, b1, b2;
  cin >> x1 >> x2 >> y1 >> y2 >> a1 >> a2 >> b1 >> b2;
  int min = (x1 + x2) + (y1 + y2) / 2;
  cout << min << endl;
}

int main() {
  solution();
  return 0;
}
