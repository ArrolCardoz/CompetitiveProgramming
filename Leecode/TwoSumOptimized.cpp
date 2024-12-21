#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> hashing;
  for (int i = 0; i < nums.size(); i++) {
    int numFirst = nums[i];
    int numSecond = target - numFirst;

    if (hashing.find(numSecond) != hashing.end()) {
      cout << numFirst << " " << numSecond << endl;
      vector<int> ans;
      ans.push_back(hashing[numSecond]);
      ans.push_back(i);
      return ans;
    } else {
      hashing[numFirst] = i;
    }
  }
  vector<int> ans;
  return ans;
}

int main() {
  int target = 6;
  vector<int> nums = {3, 2, 4};
  cout << "[ ";
  for (auto& it : twoSum(nums, target)) {
    cout << it << ' ';
  }
  cout << "] ";

  return 0;
}