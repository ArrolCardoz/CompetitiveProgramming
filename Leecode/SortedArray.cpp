// https://www.youtube.com/watch?v=4iT-GhvSKzc&t=1409s
#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int> nums, int index) {
  if (index == 1 || index == 0) return true;

  return nums[index - 1] <= nums[index] && isSorted(nums, index - 1);
}

int main() {
  vector<int> nums = {1, 2, 6, 4, 5};
  if (isSorted(nums, nums.size() - 1))
    cout << "True";
  else
    cout << "False";
  return 0;
}