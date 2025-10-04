#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  set<string> s1, s2;
  n--;
  for (int i = 0; i < m; i++) {
    string input;
    cin >> input;
    s1.insert(input);
  }
  while (n--) {
    for (int i = 0; i < m; i++) {
      string input;
      cin >> input;
      if (s1.find(input) != s1.end()) {
        s2.insert(input);
      }
    }
    s1 = s2;
    s2.clear();
  }
  cout << s1.size() << endl;
  for (auto& it : s1) cout << it << endl;
}