#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, b;
  cin >> w >> b;

  cout << fixed << setprecision(10) << (w + b) - hypot(w, b) << endl;
  return 0;
}