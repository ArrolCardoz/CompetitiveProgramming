#include <bits/stdc++.h>
using namespace std;

void solution() {}

int main() {
  string target;
  int n;
  cin >> target >> n;
  int ans = 0;

  string input;
  while (cin >> input) {
    int i = 0;
    while ((target.size() - (input.size() - i)) >= 0) {
      if (input.find(target, i) == string::npos) break;
      i = input.find(target, i);
      ans++;
      i++;
      //   cout << i << input << endl;
    }
  }

  cout << ans << endl;
  return 0;
}