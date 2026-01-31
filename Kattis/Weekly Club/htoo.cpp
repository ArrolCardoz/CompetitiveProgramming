#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  unordered_map<char, int> mol, want;
  char prev = ' ';
  int j = 0;
  for (int i = 0; i < str.size(); i = j) {
    if (str[i] >= '0' && str[i] <= '9') {
      int n = str[i] - '0';

      for (j = i + 1; j < str.size(); j++) {
        if (str[j] >= '0' && str[j] <= '9') {
          n *= 10;
          n += str[j] - '0';
        } else {
          break;
        }
      }

      cerr << prev << ' ' << n << endl;
      mol[prev] += (n - 1);
    } else {
      j = i + 1;
      mol[str[i]]++;
      prev = str[i];
    }
  }
  int input;
  cin >> input;
  for (auto& [m, n] : mol) {
    n *= input;
    cerr << m << ' ' << n << endl;
  }
  cerr << endl;
  cin >> str;
  for (int i = 0; i < str.size(); i = j) {
    if (str[i] >= '0' && str[i] <= '9') {
      int n = str[i] - '0';
      for (j = i + 1; j < str.size(); j++) {
        if (str[j] >= '0' && str[j] <= '9') {
          n *= 10;
          n += str[j] - '0';
        } else {
          break;
        }
      }
      cerr << prev << ' ' << n << endl;
      want[prev] += (n - 1);

    } else {
      j = i + 1;
      want[str[i]]++;
      prev = str[i];
    }
  }
  int ans = INT_MAX;
  for (auto& [m, n] : want) {
    int have = mol[m] / n;
    ans = min(ans, have);
  }
  cout << ans << endl;
  return 0;
}