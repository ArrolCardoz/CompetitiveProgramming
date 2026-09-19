#include <bits/stdc++.h>
using namespace std;

void solution() {
  unordered_map<string, int> freqTable;
  string temp, gear;
  int n;
  cin >> n;
  while (n--) {
    cin >> temp >> gear;
    freqTable[gear]++;
  }
  int combination = 1;
  for (auto& it : freqTable) {
    combination *= it.second + 1;
  }
  cout << combination - 1 << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}