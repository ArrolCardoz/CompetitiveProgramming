#include <bits/stdc++.h>
using namespace std;

void soluton(int a, int b, int c) {
  int dist1, dist2;
  bool isTrue = true;
  dist1 = b - a;
  dist2 = c - b;
  if ((dist1 > 0 && dist2 < 0) || (dist1 < 0 && dist2 > 0)) {
    cout << "turned";
    isTrue = false;
  }

  dist1 = abs(dist1);
  dist2 = abs(dist2);
  // cout << dist1 << " " << dist2;
  if (isTrue) {
    if (dist1 == dist2)
      cout << "cruised";

    else if (dist1 > dist2)
      cout << "braked";
    else if (dist1 < dist2)
      cout << "accelerated";
  }
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  soluton(a, b, c);
  return 0;
}