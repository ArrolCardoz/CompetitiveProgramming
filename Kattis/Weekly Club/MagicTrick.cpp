#include <bits/stdc++.h>
using namespace std;

int solution(string n) {
  sort(n.begin(), n.end());
  bool isTrue = false;
  char prev = '0';
  for (auto &it : n) {
    if (it == prev && isTrue) return 0;
    // cout << prev << " " << it << endl;
    prev = it;
    isTrue = true;
  }

  return 1;
}

int main() {
  string s;
  cin >> s;
  cout << solution(s);
  return 0;
}