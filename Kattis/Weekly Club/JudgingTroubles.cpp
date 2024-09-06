#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
  unordered_map<string, int> map1;
  unordered_map<string, int> map2;
  unordered_map<string, string> str;

  string input;
  int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> input;
    map1[input]++;
    str[input] = input;
  }
  for (int i = 0; i < n; i++) {
    cin >> input;
    map2[input]++;
    str[input] = input;
  }
  for (auto &it : str) {
    max += min(map1[it.second], map2[it.second]);
    //   cout << it.second << " " << map1[it.second] << ' ' << map2[it.second]
    //   << endl;
  }
  return max;
}

int main() {
  int n;
  cin >> n;
  cout << solution(n);
  return 0;
}