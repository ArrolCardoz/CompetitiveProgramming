#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  auto zero = str.end() - 1;
  auto one = str.end() - 2;
  auto two = str.end() - 3;
  //   cout << *zero << " " << *one << " " << *two << endl;
  long long ans = 0;
  string final;
  while (zero >= str.begin()) {
    ans = (*zero - '0');
    if (one >= str.begin()) ans += (*one - '0') * 2;
    if (two >= str.begin()) ans += (*two - '0') * 4;

    // cout << ans << endl;
    final.push_back(ans + '0');
    zero -= 3;
    one -= 3;
    two -= 3;
    ans = 0;
  }
  reverse(final.begin(), final.end());
  cout << final << endl;
  return 0;
}