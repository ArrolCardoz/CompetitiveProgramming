#include <bits/stdc++.h>
using namespace std;

bool bruteForce(vector<int>& freqTable, vector<vector<int>>& cards, int idx,
                int n) {
  // cerr << idx << ' ' << n << endl;
  if (idx == n) return true;
  for (int i = 0; i < 2; i++) {
    if (freqTable[cards[idx][i]] < 1) {
      freqTable[cards[idx][i]]++;
      idx++;
      if (bruteForce(freqTable, cards, idx, n)) return true;
      idx--;
      freqTable[cards[idx][i]]--;
    }
  }
  return false;
}

void solution() {
  int n;
  cin >> n;
  vector<vector<int>> cards(n, vector<int>(2, 0));
  for (auto& i : cards) {
    cin >> i[0] >> i[1];
  }
  vector<int> ans(2 * n, 0);
  if (bruteForce(ans, cards, 0, n))
    cout << "possible" << endl;
  else
    cout << "impossible" << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}