#include <bits/stdc++.h>
using namespace std;
long long zeros(long long n) {
  long long sum = 1;
  for (long long i = 2; i <= n; i++) {
    sum = sum * i;
    cout << n << endl;
  }
  cout << sum << endl;
  long long mult = 10;
  long long ans = 0;
  for (long long i = 1; i < sum; i++)
    if ((sum % mult) == 0) {
      mult = mult * 10;
      ans++;
    } else
      break;
  return ans;
}
int main() {
  long long a;
  cin >> a;
  cout << zeros(a);
}
