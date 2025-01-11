#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string str1, str2;
  cin >> str1;
  vector<string> ans;
  string final;
  if (n == 1) {
    cout << str1 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (!(cin >> str2)) break;
    final = str2;
    // cout << "TEsT " << str1 << ' ' << str2 << ' ' << i << endl;

    if (str2 == "Present!") {
      if (i < n - 1) {
        cin >> str1;
        final = str1;
        i++;
      }

    } else {
      ans.push_back(str1);
      str1 = str2;
    }
    // cout << i << endl;
  }
  // cout << "TEsT " << str1 << ' ' << str2 << "END" << endl;
  // cout << final << "FINAL" << endl;
  if (final != "Present!") {
    ans.push_back(final);
  }
  if (ans.size() == 0)
    cout << "No Absences" << endl;
  else
    for (auto &a : ans) cout << a << endl;
  return 0;
}