#include <bits/stdc++.h>
using namespace std;

int main() {
  int upper = INT_MAX, lower = INT_MIN, n, a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    upper = min(upper, b);
    lower = max(lower, a);
  }
  if (lower > upper)
    cout << "edward is right" << endl;
  else
    cout << "gunilla has a point" << endl;
  return 0;
}