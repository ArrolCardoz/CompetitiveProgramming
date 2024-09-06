#include <bits/stdc++.h>
using namespace std;

int solution() {
  int n;
  cin >> n;
  unordered_map<string, int> m;
  string str;

  for (int i = 0; i < n; i++) {
    cin >> str;
    m[str]++;
  }
  return m.size();
}
int main() {
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 0; i < n; i++) ans.push_back(solution());

  for (auto &it : ans) cout << it << endl;
}