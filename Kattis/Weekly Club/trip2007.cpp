/*
Idea: Keep track of the frequency and insert each in a different array
Implementation: The frequency need to be sorted so I used a map and loop through
the map and store the answer in vector of vector

One optimization that can be done is to reserve the answer array to the size of
the map so that we need do not need to allocate the memeory every 2^n times.
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

bool solution(bool& ok) {
  // initalization
  int n, input;
  if (cin >> n && n == 0) return false;
  if (ok) cout << endl;
  ok = true;
  map<int, int> freqTable;
  int maxNum = -1;

  // reading input
  for (int i = 0; i < n; i++) {
    cin >> input;
    freqTable[input]++;
    maxNum = max(maxNum, freqTable[input]);
  }

  vector<vector<int>> ans(maxNum);
  cout << maxNum << endl;
  // Making the list
  for (auto& [key, value] : freqTable) {
    for (int i = 0; i < value; i++) {
      ans[i].push_back(key);
    }
  }

  // printing solution
  for (auto& v : ans) {
    for (int i = 0; i < (int)v.size(); i++) {
      if (i) cout << ' ';
      cout << v[i];
    }
    cout << endl;
  }
  return true;
}
int main() {
  fastIO();
  bool ok = false;
  while (solution(ok)) {
    ;
  }
  return 0;
}