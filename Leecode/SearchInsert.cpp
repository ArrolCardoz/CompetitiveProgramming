// 35
#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  int low = 0;
  int high = nums.size() - 1;
  int mid = 0;
  if (target > nums[high]) {
    return high + 1;
  } else if (target < nums[low]) {
    return 0;
  } else {
    while (low <= high) {
      mid = low + (high - low) / 2;
      // cout << "LOW" << low << "LOW" << high << endl;

      // cout << "MID" << nums[mid] << endl;
      if (nums[mid] == target)
        return mid;
      else {
        if (nums[mid] > target)
          high = mid - 1;
        else
          low = mid + 1;
      }
    }
  }
  //   cout << "LOW" << low << "LOW" << high << endl;

  return low;
}

int main() {
  vector<int> nums = {1, 3};
  int target;
  cin >> (target);
  cout << searchInsert(nums, target);
  return 0;
}