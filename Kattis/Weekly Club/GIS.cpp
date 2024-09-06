#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n, test, max = 0;
  cin >> n;
  vector<int> answer;
  for (int i = 0; i < n; i++) {
    cin >> test;
    if (test > max) {
      answer.push_back(test);
      max = test;
    }
  }
  cout << answer.size() << endl;
  for (auto &it : answer) cout << it << " ";
}

int main() {
  solution();
  return 0;
}