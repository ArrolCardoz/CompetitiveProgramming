#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 8;
  int i = 0;
  string str;
  vector<vector<int>> counters(4, vector(15, 0));
  int queenCtr = 0;

  // 0->row
  // 1->col
  // 2->rightDiag
  // 3->leftDiag
  while (n--) {
    cin >> str;
    for (int j = 0; j < 8; j++) {
      if (str[j] != '*') continue;
      queenCtr++;

      counters[0][i]++;
      counters[1][j]++;
      counters[2][i + j]++;

      counters[3][i - j + 7]++;
    }
    i++;
  }
  int maxNum;
  if (queenCtr != 8) {
    cout << "invalid" << endl;
    return 0;
  }
  for (auto& it : counters) {
    maxNum = *max_element(it.begin(), it.end());
    if (maxNum > 1) {
      cout << "invalid" << endl;
      return 0;
    }
  }
  cout << "valid" << endl;
  return 0;
}