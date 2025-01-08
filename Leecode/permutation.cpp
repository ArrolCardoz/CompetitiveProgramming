// https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>
using namespace std;

void permuteRecussion(vector<int> &nums, vector<vector<int>> &ans, int index) {
  // base case
  if (index >= nums.size()) {
    ans.push_back(nums);
    return;
  }
  for (int i = index; i < nums.size(); i++) {
    swap(nums[index], nums[i]);
    permuteRecussion(nums, ans, index + 1);
    swap(nums[index], nums[i]);  // backtracking
  }
}
vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> ans;
  permuteRecussion(nums, ans, 0);
  return ans;
}

int main() {
  vector<int> nums = {1};
  for (auto &a : permute(nums)) {
    for (auto &b : a) cout << b << ' ';
    cout << endl;
  }
  return 0;
}
