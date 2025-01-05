// https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

void subsetsRecus(vector<int>& num, int index, vector<vector<int>>& ans,
                  vector<int> current) {
  index++;
  if (index == num.size()) {
    ans.push_back(current);
    return;
  }
  // when we don't select the number
  subsetsRecus(num, index, ans, current);
  current.push_back(num[index]);
  subsetsRecus(num, index, ans, current);
}

vector<vector<int>> subsets(vector<int>& nums) {
  int index = -1;
  vector<vector<int>> ans;
  vector<int> current;
  subsetsRecus(nums, index, ans, current);
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 3};
  for (auto& it : subsets(nums)) {
    for (auto& at : it) cout << at << ' ';
    cout << endl;
  }

  return 0;
}