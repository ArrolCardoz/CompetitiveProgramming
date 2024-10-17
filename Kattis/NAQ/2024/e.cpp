
#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  map<int, int> num;
  for (int i = 0; i < n * 10; i++) {
    for (int j = 0; j < 5; j++) {
      int input;
      cin >> input;
      num[input]++;
    }
  }
  bool ans = true;

  for (auto &it : num) {
    if (it.second > n * 2) {
      cout << it.first << endl;
      ans = false;
    }
  }
  if (ans) cout << -1;
}

int main() {
  solution();
  return 0;
}
