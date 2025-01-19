#include <bits/stdc++.h>
using namespace std;

bool solution(int k) {
  unordered_map<int, int> coursesTaken;
  bool ans = true;
  int m, r, c, temp;

  cin >> m;
  while (k--) {
    cin >> temp;
    coursesTaken[temp]++;
  }
  while (m--) {
    int count = 0;
    cin >> c >> r;
    while (c--) {
      cin >> temp;
      if (coursesTaken.find(temp) != coursesTaken.end()) count++;
    }
    if (count < r) ans = false;
  }
  return ans;
}

int main() {
  int k, m;

  while (true) {
    cin >> k;
    if (k == 0) return 0;
    if (solution(k))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}