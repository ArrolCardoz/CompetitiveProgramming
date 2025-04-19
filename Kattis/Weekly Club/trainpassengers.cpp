#include <bits/stdc++.h>
using namespace std;

int main() {
  long long maxCapacity, n;
  cin >> maxCapacity >> n;
  long long left, enter, wait;
  long long capacity = 0;
  bool ans = true;
  for (int i = 0; i < n; i++) {
    cin >> left >> enter >> wait;
    if (i == 0 && left > 0) {
      cout << "impossible" << endl;
      ans = false;
      break;
    }
    if (i == n - 1 && (wait > 0 || enter > 0)) {
      cout << "impossible" << endl;
      ans = false;
      break;
    }
    capacity += enter;
    capacity -= left;
    if (capacity > maxCapacity || capacity < 0) {
      cout << "impossible" << endl;
      ans = false;
      break;
    }
    if (capacity < maxCapacity && wait > 0) {
      cout << "impossible" << endl;
      ans = false;
      break;
    }
  }
  if (!ans) return 0;
  if (capacity != 0)
    cout << "impossible" << endl;
  else
    cout << "possible" << endl;
  return 0;
}