// https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

void subsetsRecus(vector<int>& num, int index, vector<vector<int>>& ans,
                  vector<int> current) {
  //   cout << index << endl;
  if (index >= num.size()) {
    ans.push_back(current);
    return;
  }
  // when we include
  //   cout << "=====" << num[index] << endl;
  current.push_back(num[index]);
  subsetsRecus(num, index + 1, ans, current);
  // when we don't select the number
  // we don't need repeating nums
  current.pop_back();
  int idx = index;
  while (index < num.size() && num[index] == num[idx]) {
    index++;
    // cout << index;
  }

  subsetsRecus(num, index, ans, current);
}

vector<vector<int>> subsets(vector<int>& nums) {
  int index = 0;
  vector<vector<int>> ans;
  vector<int> current;
  sort(nums.begin(), nums.end());
  subsetsRecus(nums, index, ans, current);
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 2};
  for (auto& it : subsets(nums)) {
    for (auto& at : it) cout << at << ' ';
    cout << endl;
  }

  return 0;
}