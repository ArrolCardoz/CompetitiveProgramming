#include <bits/stdc++.h>
using namespace std;

bool solution(vector<int> nums) {
  unordered_map<long long, int> map;
  for (auto &it : nums) {
    map[it]++;
    // cout << map[it] << endl;
    if (map[it] > 1) return true;
  }

  return false;
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  solution(nums);
  return 0;
}