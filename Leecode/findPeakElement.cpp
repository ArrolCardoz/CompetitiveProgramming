// 162
#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
  int size = nums.size() - 1;
  int upperBound = size;
  int lowerBound = 0;
  if (size == 0) return 0;
  if (nums[0] > nums[1]) return 0;
  if (nums[size] > nums[size - 1]) return size;

  while (lowerBound <= upperBound) {
    int mid = lowerBound + (upperBound - lowerBound) / 2;
    // Check if the middle element is a peak
    bool leftCheck =
        (mid == 0 ||
         nums[mid - 1] < nums[mid]);  // Ensure mid is not the first element
    bool rightCheck =
        (mid == size ||
         nums[mid] > nums[mid + 1]);  // Ensure mid is not the last element

    if (leftCheck && rightCheck) {
      return mid;
    }
    if (nums[mid] < nums[mid + 1])
      lowerBound = mid + 1;
    else
      upperBound = mid - 1;
    // cout << lowerBound << " " << upperBound << " " << mid << endl;
  }
  return -1;
}

int main() {
  vector<int> nums = {1};
  cout << findPeakElement(nums);
  return 0;
}