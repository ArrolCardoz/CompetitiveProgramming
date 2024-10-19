#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  vector<int> ans;
  int num1Ptr = 0;
  int num2Ptr = 0;
  for (int i = 0; i < m + n; i++) {
    if (num1Ptr >= m) {
      ans.push_back(nums2[num2Ptr]);

      num2Ptr++;

      continue;
    }
    if (num2Ptr >= n) {
      ans.push_back(nums1[num1Ptr]);

      num1Ptr++;

      continue;
    }
    if (nums1[num1Ptr] < nums2[num2Ptr]) {
      ans.push_back(nums1[num1Ptr]);

      num1Ptr++;
    } else {
      ans.push_back(nums2[num2Ptr]);

      num2Ptr++;
    }
  }
  nums1 = ans;
  //   for (auto it : ans) cout << it << ' ';
}

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> nums2 = {2, 5, 6};
  int n = 3;

  merge(nums1, m, nums2, n);
  return 0;
}