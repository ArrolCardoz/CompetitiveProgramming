// 33
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
  int lowerBound = 0;
  int size = nums.size() - 1;
  int upperBound = size;
  if (size + 1 < 3) {
    if (nums[upperBound] == target)
      return upperBound;
    else if (nums[0] == target)
      return 0;
    return -1;
  }
  while (lowerBound <= upperBound) {
    int mid = lowerBound + (upperBound - lowerBound) / 2;
    cout << nums[mid] << endl;
    cout << mid << endl;
    if (nums[mid] == target) return mid;
    if (nums[lowerBound] <= nums[mid]) {
      if (target >= nums[lowerBound] && target < nums[mid])
        upperBound = mid - 1;
      else

        lowerBound = mid + 1;
    }

    else {
      if (target > nums[mid] && target <= nums[upperBound]) {
        // cout << "hi";
        lowerBound = mid + 1;

      } else {
        // cout << "hello";
        upperBound = mid - 1;
      }
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {5, 1, 2, 3, 4};
  int target = 1;
  cout << search(nums, target);
  return 0;
}