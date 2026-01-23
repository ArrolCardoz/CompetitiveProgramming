#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  string ans;
  int carry = 0;
  cin >> a >> b;

  int loop = max(a.size(), b.size());

  a = string(loop - a.size(), '0') + a;
  b = string(loop - b.size(), '0') + b;
  //   cout << a << endl << b << endl;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < loop; i++) {
    int sum = (a[i] - '0') + (b[i] - '0') + carry;
    if (sum >= 10) {
      carry = 1;
      ans += (sum % 10) + '0';
    } else {
      carry = 0;
      //   cout << sum;
      ans += sum + '0';
    }
  }
  if (carry) ans += '1';
  //   for (auto& it : ans) cout << it;
  //   cout << endl;
  for (int i = ans.size() - 1; i > -1; i--) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
}