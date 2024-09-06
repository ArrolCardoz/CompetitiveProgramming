#include <bits/stdc++.h>
using namespace std;

void solution() {
  vector<vector<long long>> candlesGroup;
  long long n, h, c;
  long long num;
  long long ans = 0;
  bool toBreak = true;
  cin >> n >> h >> c;
  vector<long long> candles(h);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < h; j++) {
      cin >> candles[j];
    }
    sort(candles.begin(), candles.end());
    // cout << "sprt" << endl;
    // for (auto &it : candles) cout << it << " ";
    // cout << endl;
    candlesGroup.push_back(candles);
  }

  vector<long long> least;
  long long counter = 0;

  //   cout << c << "C VALUE" << endl;
  while ((counter < h) && toBreak) {
    for (auto &it : candlesGroup) {
      num = it[counter];
      least.push_back(num);
    }

    sort(least.begin(), least.end());
    // cout << least.size() << endl;
    // for (auto &it : least) cout << it << " ";
    // cout << endl;

    for (auto &it : least) {
      //  cout << c - it << "C VALUE" << endl;
      if (0 > c - it) {
        toBreak = false;
        break;
      }
      c -= it;
      ans++;
    }
    if (toBreak) {
      least.clear();
      counter++;
      continue;
    }
    break;
  }
  cout << ans;
}

int main() {
  solution();
  return 0;
}
