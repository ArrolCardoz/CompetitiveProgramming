#include <bits/stdc++.h>
using namespace std;

int main() {
  int limit, n;
  cin >> limit >> n;
  int current = 0;
  int ans = 0;
  while (n--) {
    string str;
    int people;
    cin >> str >> people;
    if (str == "enter") {
      if ((current + people) > limit)
        ans++;
      else
        current += people;
    } else
      current -= people;
  }
  cout << ans << endl;
  return 0;
}