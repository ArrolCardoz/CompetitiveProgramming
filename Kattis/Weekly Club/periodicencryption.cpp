#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, ctr = -1, curr = 0;
  string str;
  cin >> n >> k >> str;
  bool visited[n] = {false};
  while (curr != n) {
    for (int i = 0; i < k;) {
      ctr = (ctr + 1) % n;
      if (visited[ctr]) continue;
      i++;
    }
    visited[ctr] = true;
    cout << str[ctr];
    curr++;
  }
  return 0;
}