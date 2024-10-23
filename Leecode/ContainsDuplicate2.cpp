// 219
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_map<int, int> map;
  int leftCtr;
}

int main() {
  vector<int> nums = {};
  int k = 0;
  if (containsNearbyDuplicate(nums, k))
    cout << "True";
  else
    cout << "False";
  return 0;
}