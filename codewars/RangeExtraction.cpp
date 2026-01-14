#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string range_extraction(vector<int> args) {
  sort(args.begin(), args.end());
  int previous = args[0];
  int count = 1;
  string ans = "";
  ans += to_string(previous);
  for (int i = 1; i < (int)args.size(); i++) {
    cout << previous << endl;
    if (previous == args[i] - 1) {
      count++;
      previous = args[i];
    } else {
      if (count > 2) {
        ans += "-";
        ans += to_string(previous);
      } else if (count == 2) {
        ans += ",";
        ans += to_string(previous);
      }
      ans += ",";
      ans += to_string(args[i]);
      previous = args[i];
      count = 1;
    }
  }
  if (count > 2) {
    ans += "-";
    ans += to_string(previous);
  } else if (count == 2) {
    ans += ",";
    ans += to_string(previous);
  }

  return ans;
}
int main() {
  cout << range_extraction({-10, -9, -8, -6, -3, -2, -1, 0,  1,  3,  4, 5,
                            7,   8,  9,  10, 11, 14, 15, 17, 18, 19, 20});
  return 0;
}