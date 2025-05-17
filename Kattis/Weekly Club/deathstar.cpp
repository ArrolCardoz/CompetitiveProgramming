#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int input;
      cin >> input;
      if (i == j) continue;
      arr[i] |= input;
      arr[j] |= input;
    }
  }
  for (auto &ans : arr) cout << ans << ' ';
  return 0;
}