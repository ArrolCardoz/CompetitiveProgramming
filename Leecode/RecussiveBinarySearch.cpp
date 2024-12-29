// https://leetcode.com/problems/binary-search/description/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int target, int start, int end) {
  if (start == end || start > end) {
    if (nums[start] == target) return start;
    return -1;
  }
  int mid = start + (end - start) / 2;
  if (nums[mid] == target)
    return mid;
  else if (nums[mid] >= target)
    return binarySearch(nums, target, start, mid - 1);
  return binarySearch(nums, target, mid + 1, end);
}
int search(vector<int>& nums, int target) {
  int end = nums.size() - 1;
  return binarySearch(nums, target, 0, end);
}