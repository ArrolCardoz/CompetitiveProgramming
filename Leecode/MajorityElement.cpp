#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
  pair<int, int> ans = {0, 0};
  for (auto& it : nums) {
    if (it == ans.first)
      ans.second++;
    else {
      ans.second--;
      if (ans.second < 0) {
        ans.first = it;
        ans.second++;
      }
    }
  }
  return ans.first;
}

int main() {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  cout << majorityElement(nums);
  return 0;
}