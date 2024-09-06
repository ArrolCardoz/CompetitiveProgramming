#include <bits/stdc++.h>
using namespace std;
void solution() {
  int n, counter = 0;
  string code, player;
  int common = 0;
  cin >> n;
  cin >> code >> player;
  map<char, int> arr1;
  map<char, int> arr2;

  for (int i = 0; i < n; i++) {
    if (code[i] == player[i]) {
      counter++;
      continue;
    }
    arr1[code[i]]++;
    arr2[player[i]]++;
  }

  int a;
  for (auto &i : arr2)
    if (arr1.count(i.first) > 0) {
      auto it = arr1.find(i.first);
      a = min(i.second, it->second);
      common += a;
      i.second -= a;
      it->second -= a;

      // cout << min(i.second, it->second) << endl;
    }
  // auto ite = arr2.begin();

  //   for (auto &i : arr1) {
  //     cout << i.first << " " << i.second << endl;
  //     cout << ite->first << " " << ite->second << endl;
  //   }

  cout << counter << " " << common;
}

int main() {
  solution();
  return 0;
}