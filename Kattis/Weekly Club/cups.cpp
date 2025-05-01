#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  map<int, vector<string>> ans;
  cin >> n;
  while (n--) {
    int n;
    string str;
    cin >> str;
    if (str[0] >= '0' && str[0] <= '9') {
      n = stoi(str);
      cin >> str;
      ans[n].push_back(str);
    } else {
      cin >> n;
      ans[n * 2].push_back(str);
    }
  }
  for (auto &it : ans) {
    // cout << it.first << endl;
    for (auto &a : it.second) cout << a << endl;
  }
}