#include <bits/stdc++.h>
using namespace std;

string mapping[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main() {
  int n;
  cin >> n;
  vector<string> words(n);

  for (auto& it : words) {
    cin >> it;
    for (auto& a : it) {
      for (int i = 0; i < 8; i++) {
        if (mapping[i].find(a) != mapping[i].npos) {
          a = (i + 2) + '0';
        }
      }
    }
  }
  string input;
  int ans = 0;
  cin >> input;
  for (auto& it : words)
    if (input == it) ans++;

  cout << ans << endl;

  return 0;
}