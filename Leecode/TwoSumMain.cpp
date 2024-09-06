#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> nums = {3, 3};
  int target = 6;
  map<int, int> m;
  m[nums[0]] = 0;

  for (int i = 1; i < nums.size(); i++) {
    int x = target - nums[i];
    auto it = m.find(x);
    if (it != m.end() && (*it).second != i) {
      //  cout << x << " = " << target << " - " << nums[i] << endl;
      cout << "[" << (*it).second << ", " << i << "]" << endl;
    } else
      m[nums[i]] = i;
  }

  // for (auto &i : m) cout << i.first << " " << i.second << endl;
}
