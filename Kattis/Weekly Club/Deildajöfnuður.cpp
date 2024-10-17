#include <bits/stdc++.h>
using namespace std;

void repeat(string str) {}

int main() {
  int n;
  int ans;
  unordered_map<string, int> count;
  string loop;
  cin >> n;
  string str;
  cin >> str;
  int limit = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (j == i) count.clear();
      loop = str[j];
      count[loop]++;
      auto it = *count.begin();
      if (count[loop] > it.second) break;
      if (count[loop] > 1)
        for (auto &itt : count) {
          int highest = 0;
          if (highest) {
          }
        }
    }
  }
}