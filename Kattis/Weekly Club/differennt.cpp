#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b;
  while (cin >> a >> b) {
    long long A = max(a, b);
    long long B = min(a, b);
    cout << A - B << endl;
  }

  return 0;
}