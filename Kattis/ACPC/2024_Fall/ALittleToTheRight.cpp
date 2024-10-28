#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr) {
  int previous = -1;
  sort(arr.begin(), arr.end());

  for (auto &it : arr) {
    // cout<<it<<' '<< previous<<endl;
    // cout<<endl;
    if (previous == it) return false;
    previous = it;
  }
  // cout<<" TRUE"<<endl;
  return true;
}

void solution() {
  int numTrophies;
  int numProperties;

  cin >> numTrophies >> numProperties;

  vector<vector<int>> properties;
  for (int i = 0; i < numTrophies; i++) {
    vector<int> temp = {};
    for (int j = 0; j < numProperties; j++) {
      int n;
      cin >> n;
      temp.push_back(n);
      // cout<<n<< ' ';
    }
    // cout<<endl;

    properties.push_back(temp);
  }
  vector<int> arr;
  unordered_map<int, string> sorting;
  unordered_map<string, int> ans;
  for (int j = 0; j < numProperties; j++) {
    sorting.clear();
    arr = {};
    for (int i = 0; i < numTrophies; i++) {
      sorting[properties[i][j]] = to_string(i);
      arr.push_back(properties[i][j]);
      // cout<<i<<' '<<j<<'='<<properties[i][j]<<endl;
    }
    // cout<<endl;
    if (isValid(arr)) {
      string str = "";
      for (auto &it : arr) {
        str += sorting[it];
      }
      ans[str]++;
    }
  }
  //  for(auto &it:ans)cout<<it.first<< ' '<<it.second<<endl;
  cout << ans.size();
}

int main() {
  solution();
  return 0;
}