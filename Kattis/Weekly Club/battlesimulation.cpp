#include <bits/stdc++.h>
using namespace std;
int main() {
  string str = "";
  cin >> str;
  char ans = ' ';
  map<char, char> counter = {{'R', 'S'}, {'B', 'K'}, {'L', 'H'}};
  for (int i = 2; i < str.size(); i++) {
    if (str.size() < 3) break;
    if (str[i] != str[i - 1] && str[i] != str[i - 2] &&
        str[i - 2] != str[i - 1]) {
      cout << 'C';
      if (i == str.size() - 1) ans = 'C';  // last 3 check
      if (i == str.size() - 2) {           // second last check
        ans = 'C';
        cout << counter[str[str.size() - 1]];
      }
      i += 2;
    } else {
      cout << counter[str[i - 2]];
      ans = counter[i - 2];
    }
  }
  if (str.size() < 2) {
    for (auto &it : str) cout << counter[it];
    return 0;
  }
  if (ans == 'C') return 0;

  cout << counter[str[str.size() - 2]];
  cout << counter[str[str.size() - 1]];
  return 0;
}