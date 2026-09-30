#include <bits/stdc++.h>
using namespace std;

// Supposed to use 64 bit int
int main() {
  int64_t a, b;
  while (cin >> a >> b) {
    int64_t A = max(a, b);
    int64_t B = min(a, b);
    cout << A - B << endl;
  }

  return 0;
}