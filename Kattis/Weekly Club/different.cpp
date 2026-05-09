#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  while (cin >> s1 >> s2) {
    if (s1 > s2) {
      string temp = s1;
      s1 = s2;
      s2 = temp;
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string ans = "";
    int carry = 0;
    for (int i = 0; i < (int)s2.size(); i++) {
      ans += ((s1[i] - '0') - (s2[i] - '0') - carry) + '0';
    }
    for (int i = (int)s2.size(); i < (int)s1.size(); i++) {
      ans += s1[i];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
  return 0;
}