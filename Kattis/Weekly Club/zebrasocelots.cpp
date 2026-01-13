#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  unsigned long long ans = 0;
  unsigned long long final = (1ULL << n) - 1;

  char c;

  for (int i = 0; i < n; i++) {
    cin >> c;
    ans <<= 1;
    if (c == 'Z') ans |= 1;
  }

  //   cerr << "ans " << ans << endl;
  //   cerr << "final " << final << endl;
  cout << final - ans << endl;
  return 0;
}