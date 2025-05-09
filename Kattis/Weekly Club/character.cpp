#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (1 << n) - n - 1 << endl;  // 2^n - n - 1
  return 0;
}
