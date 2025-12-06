#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  string str;
  vector<vector<ll>> nums;
  vector<string> operation;

  getline(cin, str);
  stringstream ss(str);
  ll num;

  while (ss >> num) {
    nums.push_back({num});
  }

  while (getline(cin, str)) {
    if (str == "-1") break;
    ll num;
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
  ll ans = 0;
  for (int i = 0; i < operation.size(); i++) {
    string c = operation[i];
    ll total = 0;
    for (auto& it : nums[i]) {
      if (c == "*") {
        if (total == 0) total = 1;
        total *= it;
      } else
        total += it;
      //   cout << total << endl;
    }
    ans += total;
  }
  cout << ans << endl;
  return 0;
}