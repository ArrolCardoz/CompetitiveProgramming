#include <bits/stdc++.h>
using namespace std;
void solution(unordered_map<string, vector<string>> &hideous,
              vector<string> &color) {
  for (auto &it : color) {
    cout << it << " ";
    for (auto its : color) {
      if (it == its) continue;
      for (auto &hid : hideous[it]) {
        if (hid == its) continue;
        cout << its << " ";
      }
    }
    cout << endl;
  }
}
int main() {
  unordered_map<string, vector<string>> hideous;
  vector<string> color;
  int a;
  cin >> a;
  int i = 0;
  int n;
  string str, str2;
  while (i < a) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> str;
      color.push_back(str);
    }
    for (auto &it : color) cout << it << endl;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> str >> str2;
      hideous[str].push_back(str2);
    }
    solution(hideous, color);
    i++;
  }

  return 0;
}
