#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  string str;
  vector<vector<string>> nums;
  vector<vector<string>> newNums;

  vector<string> operation;
  vector<string> input;

  getline(cin, str);
  input.push_back(str);
  stringstream ss(str);
  string num;

  while (ss >> num) {
    nums.push_back({num});
  }

  while (getline(cin, str)) {
    if (str == "-1") break;
    input.push_back(str);
    string num;
    int counter = 0;
    stringstream ss2(str);
    while (ss2 >> num) {
      nums[counter].push_back(num);
      counter++;
    }
  }

  getline(cin, str);
  string c;
  stringstream ss3(str);

  while (ss3 >> c) {
    operation.push_back(c);
  }

  int temp = nums.size();
  int test[temp] = {0};
  ll ans = 0;
  for (int i = 0; i < (int)nums.size(); i++) {
    int maxWidth = -1;
    for (auto& m : nums[i]) {
      maxWidth = max((int)m.size(), maxWidth);
    }
    test[i] = maxWidth;
  }

  newNums.resize(nums.size());

  for (int i = 0; i < input.size(); i++) {
    int LowerPointer = 0;

    for (int j = 0; j < nums.size(); j++) {
      int width = test[j];
      if (LowerPointer + width > input[i].size()) break;

      string slice = input[i].substr(LowerPointer, width);
      newNums[j].push_back(slice);

      LowerPointer += width + 1;
    }
  }

  nums = newNums;
  //   // resize all strings
  //   for (int i = 0; i < (int)nums.size(); i++) {
  //     for (auto& m : nums[i]) {
  //       m.resize(test[i], ' ');
  //     }
  //   }
  // each sum loop
  for (int i = 0; i < (int)nums.size(); i++) {
    ll total = 0;
    string c = operation[i];

    // loop of size
    for (int j = test[i] - 1; j >= 0; j--) {
      ll n = 0.1;
      ll counter = 1;
      // get n
      for (int k = 0; k < (int)nums[i].size(); k++) {
        if (nums[i][k][j] != ' ') {
          n *= 10;
          n += (nums[i][k][j] - '0') * counter;
        }
      }
      // add up
      //   cout << n << ' ' << c << endl;
      if (c == "*") {
        if (total == 0) total = 1;
        total *= n;
      } else
        total += n;
    }
    ans += total;
  }

  cout << ans << endl;
  return 0;
}