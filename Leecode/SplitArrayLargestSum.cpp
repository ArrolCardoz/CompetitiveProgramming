// 410
#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int>& nums, int k, int maxAllowedPages) {
  int count = 1;
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (count > k || nums[i] > maxAllowedPages) return false;
    sum += nums[i];
    if (sum > maxAllowedPages) {
      count++;
      sum = nums[i];
    }
  }
  if (count > k) return false;
  return true;
}
int splitArray(vector<int>& nums, int k) {
  vector<int> sumNum;
  int sum = 0;
  int ans = -1;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
  }
  if (k == 1) return sum;
  for (int i = 0; i < sum; i++) {
    sumNum.push_back(i);
  }
  int st = 0;
  int end = sumNum.size() - 1;
  int mid = 0;
  while (st <= end) {
    mid = st + (end - st) / 2;
    // cout << sumNum[mid] << ' ';
    if (isValid(nums, k, sumNum[mid])) {
      end = mid - 1;
      ans = mid;
    } else
      st = mid + 1;
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  int k = 1;
  cout << splitArray(nums, k);
  return 0;
}