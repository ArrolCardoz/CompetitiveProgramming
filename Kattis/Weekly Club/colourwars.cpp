#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int input;
  int ans = 0;

  unordered_map<int, int> votes;
  while (n--) {
    cin >> input;
    votes[input]++;
  }
  for (auto &[k, v] : votes) {
    int groupsize = k + 1;

    ans += (groupsize * ((k + v) / groupsize));
    // cout << ans << '=' << groupsize << '*' << (v + k / groupsize) << ' ' << k
    //      << ' ' << v << endl;
    // cout << k << '+' << v << '/' << groupsize << '=' << ((k + v) / groupsize)
    //      << endl;
  }
  cout << ans << endl;
  return 0;
}