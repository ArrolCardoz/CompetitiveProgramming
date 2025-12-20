#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<string> sorted = strs;
  unordered_map<string, vector<string>> ans;
  for (int i = 0; i < sorted.size(); i++) {
    sort(sorted[i].begin(), sorted[i].end());
    ans[sorted[i]].push_back(strs[i]);
  }
  vector<vector<string>> realAns;
  for (auto& [m, n] : ans) realAns.push_back(n);

  return realAns;
}

int main() { return 0; }