// 238
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> ans;
  ans.push_back(1);
  ans.push_back(nums[0]);

  int suffix = 1;
  // this calculates the prefix
  for (int i = 1; i < nums.size() - 1; i++) ans.push_back(ans[i] * nums[i]);
  //   for (auto& it : ans) cout << it << endl;
  for (int i = nums.size() - 2; i >= 0; i--) {
    suffix *= nums[i + 1];
    // cout << suffix << endl;

    ans[i] = ans[i] * suffix;
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  for (auto& it : productExceptSelf(nums)) cout << it << " ";
  // cout << nums.size() << "SIZE";
  return 0;
}