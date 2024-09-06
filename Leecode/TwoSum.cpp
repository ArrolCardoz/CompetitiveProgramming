#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    auto i = nums.begin(), j = nums.end() - 1;
    while (i != j) {
      if (*i + *j == target)
        break;
      else if (*i + *j > target)
        j--;
      else if (*i + *j < target)
        i++;
    }
    return {i, j};
  }
};