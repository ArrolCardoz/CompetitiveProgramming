// 540
#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
  int lowerBound = 0;
  int upperBound = nums.size() - 1;
  if (!upperBound) return nums[0];

  while (lowerBound <= upperBound) {
    int mid = lowerBound + (upperBound - lowerBound) / 2;
    if (upperBound - lowerBound == 0) {
      cout << "single" << upperBound - lowerBound << endl;
      return nums[lowerBound];
    }
    if (upperBound - lowerBound < 3) {
      return (nums[lowerBound] ^ nums[upperBound] ^ nums[lowerBound + 1]);
    }

    if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
      return nums[mid];

    if (mid % 2) {
      cout << nums[mid - 1] << " " << nums[mid] << "odd" << endl;
      cout << mid - 1 << " " << mid << endl;
      if (nums[mid] == nums[mid - 1])
        lowerBound = mid + 1;
      else
        upperBound = mid - 1;

    } else {
      cout << nums[mid] << " " << nums[mid + 1] << "even" << endl;
      cout << mid << " " << mid + 1 << endl;
      if (nums[mid] == nums[mid + 1])
        lowerBound = mid + 2;
      else
        upperBound = mid - 2;
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {7, 7, 10, 11, 11, 12, 12};
  cout << singleNonDuplicate(nums);
  return 0;
}