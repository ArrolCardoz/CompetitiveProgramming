#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main() {
  fastIO();
  string str;
  cin >> str;
  string best(100, 'z');
  for (int i = 1; i < (int)str.size() - 1; i++)
    for (int j = i + 1; j < (int)str.size(); j++) {
      string a = str.substr(0, i);
      string b = str.substr(i, j - i);
      string c = str.substr(j);
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      reverse(c.begin(), c.end());
      best = min(best, a + b + c);
    }
  cout << best << endl;
  return 0;
}