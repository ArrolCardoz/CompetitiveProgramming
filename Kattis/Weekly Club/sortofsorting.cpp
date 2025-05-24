#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n != 0) {
    map<string, vector<string>> order;
    while (n--) {
      string str;
      cin >> str;
      string subStr = str.substr(0, 2);
      //   cout << subStr << endl;
      order[subStr].push_back(str);
    }
    for (auto &o : order) {
      for (auto &a : o.second) cout << a << endl;
    }

    cin >> n;
  }
}