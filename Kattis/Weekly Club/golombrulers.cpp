#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solution(string str) {
  stringstream ss(str);
  int n;
  unordered_set<int> s, ans;
  int maxNum = -1;
  while (ss >> n) {
    s.insert(n);
    maxNum = max(maxNum, n);
  }
  vector<int> v(maxNum + 1, 0);
  v[0] = 2;
  ans.insert(0);

  for (auto& i : s) {
    for (auto& j : s) {
      if (i == j) continue;
      v[abs(i - j)]++;
      ans.insert(abs(i - j));
      if (v[abs(i - j)] > 2) {
        cout << "not a ruler" << endl;
        return;
      }
    }
  }
  if ((int)ans.size() != maxNum + 1) {
    cout << "missing";
    for (int i = 0; i < (int)v.size(); i++) {
      if (v[i] == 0) cout << ' ' << i;
    }
    cout << endl;
  } else {
    cout << "perfect" << endl;
  }
}
int main() {
  fastIO();
  string str;
  while (getline(cin, str)) solution(str);
  return 0;
}