#include <bits/stdc++.h>
using namespace std;

int solution(vector<int>& nums, int val) {
  int size = nums.size();
  bool isTure = true;
  int index = 0;
  while (isTure) {
    auto it = find(nums.begin(), nums.end(), val);

    if (it != nums.end()) {
      nums.erase(it);
      index++;
      continue;
    }
    isTure = false;
  }

  sort(nums.begin(), nums.end());
  return nums.size();
}

int main() {
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  cout << solution(nums, val);
  return 0;
}