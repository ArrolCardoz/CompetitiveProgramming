#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      cout << r << '-' << l << " : ";
    }
    cout << endl;
  }
  return 0;
}