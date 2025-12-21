#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  set<int> total;
  int maximum = -1, current = -1;
  int previous = nums[0];
  current++;
  total.insert(nums[0]);
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i - 1] + 1 < nums[i]) {
      for (auto& it : total) cout << total << ' ';
      maximum = max(current, maximum);
      current = 1;
      total.clear();
      total.insert(nums[i]);
    } else {
      current++;
      total.insert(nums[i]);
    }
  }
  return maximum;
}