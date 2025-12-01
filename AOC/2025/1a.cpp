#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int ans = 0;
  int counter = 50;
  while (cin >> str) {
    int num = 0;
    int start = 1;
    for (int i = str.size() - 1; i > 0; i--) {
      num += (str[i] - '0') * (start);
      start = start * 10;
    }
    cout << num << endl;
    if (str[0] == 'L') {
      // cout << (100 - num) << ' ' << counter << endl;

      counter = ((100 - num) + counter) % 100;
    } else {
      counter = (num + counter) % 100;
      // cout << ((100 - num) + counter) % 100 << endl;
    }
    // cout << counter << endl;
    if (counter == 0) ans++;
  }
  cout << ans << endl;

  return 0;
}