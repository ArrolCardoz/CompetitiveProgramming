// https://leetcode.com/problems/number-of-provinces/description/
#include <bits/stdc++.h>
using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
  int n = isConnected.size();
  vector<bool> cityChecked(n, false);
  int ans = 1;
  queue<int> city;
  city.push(0);
  bool loop = true;
  int counter = 0;
  // bfs
  while (!city.empty()) {
    while (!city.empty()) {
      int cityNum = city.front();
      city.pop();
      //   cout << cityNum << endl;
      if (cityChecked[cityNum]) continue;
      cityChecked[cityNum] = true;

      for (int i = 0; i < n; i++) {
        if (i == cityNum) continue;
        if (isConnected[cityNum][i]) {
          //   cout << i << endl;
          city.push(i);
          cityChecked[cityNum] = true;
        }
      }
    }
    // cout << counter << endl;

    counter = -1;
    for (auto it : cityChecked) {
      counter++;

      loop ^= it;
      //   cout << "COUTNER" << counter << ' ' << it << endl;

      if (!it) {
        ans++;
        // cout << "PUSH" << counter << endl;
        city.push(counter);
        break;
      }
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  cout << findCircleNum(isConnected) << endl;
  return 0;
}