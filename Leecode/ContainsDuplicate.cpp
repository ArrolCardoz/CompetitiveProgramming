#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
  unordered_map<long long, int> map;
  vector<int> ans;
  for (auto& it : nums) {
    map[it]++;
    // cout << map[it] << endl;
    if (map[it] > 1) continue;
    ans.push_back(it);
  }
  nums = ans;
  return ans.size();
}

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  cout << solution(nums);
  // for (auto& it : solution(nums)) cout << it << ' ';
  return 0;
}