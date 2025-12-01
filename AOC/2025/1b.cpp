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
    ans += num / 100;
    num %= 100;

    if (str[0] == 'L') {
      //   cout << (100 - num) << ' ' << counter << endl;

      if (counter >= num && (counter > 0)) ans++;

      counter = ((100 - num) + counter) % 100;

      //   if (after > before) ans++;
    } else {
      if ((num + counter) >= 100 && (counter > 0)) ans++;
      counter = (num + counter) % 100;
    }

    cout << ans << endl;
  }
  cout << ans << endl;

  return 0;
}