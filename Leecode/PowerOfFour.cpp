#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFout(int n) {
  if (n % 4 != 0 && n != 1) return false;
  if (n >= 4) return isPowerOfFout(n / 4);
//  cout << n << endl;
  return true;
}

int main() {
  int n;
  cin >> n;
  cout << isPowerOfFout(n);
  return 0;
}