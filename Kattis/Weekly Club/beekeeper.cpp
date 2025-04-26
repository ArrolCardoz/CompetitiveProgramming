#include <bits/stdc++.h>
using namespace std;

int main() {
  char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
  int n;
  string ans;
  string str;
  while (cin >> n && n != 0) {
    int max = -1;

    for (int i = 0; i < n; i++) {
      cin >> str;
      int temp = 0;
      if (str.size() == 1) continue;
      for (int j = 1; j < str.size(); j++) {
        if (str[j - 1] == str[j]) {
          for (auto &v : vowels)
            if (str[j] == v) {
              temp++;
              j++;
            }
        }
      }
      if (temp > max) {
        max = temp;
        ans = str;
      }
    }
    cout << ans << endl;
  }
  return 0;
}