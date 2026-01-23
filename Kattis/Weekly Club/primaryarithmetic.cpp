#include <bits/stdc++.h>
using namespace std;

bool solution(long long a, long long b) {
  if (!(a || b)) return false;
  long long mod = 10;
  long long ans = 0, carry = 0;
  for (int i = 0; a > 0 || b > 0; i++) {
    cerr << (a) << ' ' << (b) << ' ' << carry << endl;
    if (((a % mod) + (b % mod) + carry) >= 10) {
      ans++;
      carry = 1;
    } else {
      carry = 0;
    }
    a /= 10;
    b /= 10;
  }
  if (ans) {
    if (ans == 1)
      cout << ans << " carry operation." << endl;
    else
      cout << ans << " carry operations." << endl;
  } else
    cout << "No carry operation." << endl;
  return true;
}

int main() {
  long long a, b;
  do {
    cin >> a >> b;
  } while (solution(a, b));
  return 0;
}