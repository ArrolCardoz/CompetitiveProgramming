// 2965
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
  int n = grid.size();
  int twice;
  unordered_map<int, int> data;
  int missing;
  int actualSum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      data[grid[i][j]]++;
      actualSum += grid[i][j];
      if (data[grid[i][j]] == 2) twice = grid[i][j];
    }
  }
  actualSum -= twice;
  int expectedSum = ((n * n) * ((n * n) + 1)) / 2;
  missing = expectedSum - actualSum;
  vector<int> ans;
  ans.push_back(twice);
  ans.push_back(missing);
  return ans;
}

int main() { return 0; }