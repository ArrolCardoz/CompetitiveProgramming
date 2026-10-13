#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  stack<int> s;
  int n, temp;
  cin >> n;
  while (n--) {
    cin >> temp;
    s.push(temp);
  }
  bool ok = true;
  while (ok) {
    ok = false;
    int prev = -1, curr;
    stack<int> newS;
    while (!s.empty()) {
      if (prev == -1) {
        prev = s.top();
        s.pop();
        continue;
      }
      curr = s.top();
      s.pop();
      if (((curr + prev) % 2) == 0) {
        ok = true;
        prev = -1;
      } else {
        newS.push(prev);
        prev = curr;
      }
    }
    if (prev != -1) newS.push(prev);
    s = newS;
  }
  cout << s.size() << endl;
  return 0;
}