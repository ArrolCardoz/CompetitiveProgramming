#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool solution(string str, int mask) {
  stack<int> s;
  for (int i = (int)str.size() - 1; i >= 0; i--) {
    char it = str[i];
    if (it >= 'p' && it <= 't') {
      s.push((mask >> (it - 'p')) & 1);
    } else if (it == 'N') {
      int w = s.top();
      s.pop();
      s.push(!w);
    } else {
      int x = s.top();
      s.pop();
      int w = s.top();
      s.pop();
      if (it == 'K')
        s.push(w & x);
      else if (it == 'A')
        s.push(w | x);
      else if (it == 'C')
        s.push(x | !w);
      else
        s.push((w & x) || (!w & !x));
    }
  }
  return s.top();
}

int main() {
  fastIO();
  string str;
  while (cin >> str && str != "0") {
    bool ans = true;
    for (int i = 0; i < 32 && ans; i++) {
      if (!solution(str, i)) {
        ans = false;
        cout << "not" << endl;
      }
    }
    if (ans) cout << "tautology" << endl;
  }

  return 0;
}