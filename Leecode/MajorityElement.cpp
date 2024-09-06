#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
  int half = nums.size() + 0.5;
  int maxNum = 0;
  int count = 0;
  for (auto& it : nums) {
    if (it > maxNum) {
      count == 0;
      maxNum == it;
    } else if (it == maxNum)
      count++;
    if (count > half) break;
    ;
  }
  return 0;
}

int main() {
  vector<int> nums = {0};
  cout << majorityElement(nums);
  return 0;
}