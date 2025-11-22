#include <bits/stdc++.h>
using namespace std;

int main() {
  string str, ans = "";
  cin >> str;
  for (int i = 2; i < str.size(); i++) {
    if (str[i - 2] != str[i - 1] && str[i - 1] != str[i - 0] &&
        str[i - 0] != str[i - 2]) {
      ans += 'C';
      i += 3;
    } else {
      if (str[i - 2] == 'R')
        ans += 'S';
      else if (str[i - 2] == 'B')
        ans += 'K';
      else
        ans += 'H';
    }
  }
  for (int i = str.size() - 2; i < str.size(); i++) {
    if (str[i] == 'R')
      ans += 'S';
    else if (str[i] == 'B')
      ans += 'K';
    else
      ans += 'H';
  }
  cout << ans << endl;
  return 0;
}