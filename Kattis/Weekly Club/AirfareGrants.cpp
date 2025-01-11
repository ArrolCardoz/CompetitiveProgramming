#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int max = 0;
  int min = INT_MAX;
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    if (min > input) min = input;
    if (max < input) max = input;
  }
  int ans = min - (max / 2);
  if (ans < 0) ans = 0;
  cout << ans;
  return 0;
}