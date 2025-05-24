#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int minmum = INT_MAX;
  int ans, minTemp;
  int first, second, third;
  cin >> first >> second;
  for (int i = 2; i < n; i++) {
    cin >> third;
    if (minmum > max(first, third)) {
      minmum = max(first, third);
      ans = i - 1;
      minTemp = max(first, third);
    }
    first = second;
    second = third;
  }
  cout << ans << ' ' << minTemp << endl;
  return 0;
}