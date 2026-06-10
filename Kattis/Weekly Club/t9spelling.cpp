#include <bits/stdc++.h>
using namespace std;
const string key[8] = {"abc", "def",  "ghi", "jkl",
                       "mno", "pqrs", "tuv", "wxyz"};
unordered_map<char, int> mapping;

void solution() {
  char prev = ' ';
  string str;
  getline(cin, str);

  for (auto& c : str) {
    cerr << c << endl;

    if (c == ' ') {
      if (prev == mapping[c]) cout << ' ';

      cout << 0;
      prev = mapping[c];

    } else {
      if (prev == mapping[c]) cout << ' ';
      prev = mapping[c];
      for (auto& it : key[mapping[c]]) {
        if (it == c) {
          cout << mapping[c] + 2;
          break;
        }
        cout << mapping[c] + 2;
      }
    }
  }
  cout << endl;
}
int main() {
  for (int i = 0; i < 8; ++i) {
    for (char c : key[i]) {
      mapping[c] = i;
    }
  }
  int n;
  cin >> n;
  cin.ignore(100, '\n');
  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ": ";
    solution();
  }
  return 0;
}