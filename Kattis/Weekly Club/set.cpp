#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

bool check(int i, int j, int k, vector<string> str) {
  for (int a = 0; a < 4; a++) {
    if (!((str[i][a] != str[j][a] && str[j][a] != str[k][a] &&
           str[i][a] != str[k][a]) ||
          (str[i][a] == str[j][a] && str[j][a] == str[k][a])))
      return false;
  }
  return true;
}

int main() {
  fastIO();

  vector<string> str(12);
  set<tuple<int, int, int>> ans;
  for (auto& it : str) cin >> it;

  for (int i = 0; i < 12; i++) {
    for (int j = i + 1; j < 12; j++) {
      for (int k = j + 1; k < 12; k++) {
        if (i != j && j != k && k != i && check(i, j, k, str))
          ans.insert({i + 1, j + 1, k + 1});
      }
    }
  }
  if (ans.empty())
    cout << "no sets" << endl;
  else
    for (auto& [a, b, c] : ans) {
      cout << a << ' ' << b << ' ' << c << endl;
    }
  return 0;
}