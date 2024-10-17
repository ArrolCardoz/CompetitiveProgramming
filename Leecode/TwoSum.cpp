#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, vector<int>> sequence;
  for (int i = 0; i < nums.size(); i++) sequence[nums[i]].push_back(i);
  sort(nums.begin(), nums.end());
  int start = 0;
  int end = nums.size() - 1;
  while (start < end) {
    if (nums[start] + nums[end] == target) break;
    if (nums[start] + nums[end] < target) start++;
    if (nums[start] + nums[end] > target) end--;
  }
  int startNum = nums[start], endNum = nums[end];
  vector<int> ans = {sequence[startNum].back()};

  sequence[nums[start]].pop_back();
  ans.push_back(sequence[endNum].back());

  return ans;
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  for (auto& it : twoSum(nums, target)) cout << it << ' ';
  return 0;
}