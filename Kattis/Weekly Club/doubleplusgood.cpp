#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  vector<string> A;
  string str;

  while (getline(cin, str, '+')) A.push_back(str);

  int n = (int)A.size() - 1;
  unordered_set<long long> sums;

  for (int mask = 0; mask < (1 << n); mask++) {
    string curr = A[0];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        curr += A[i + 1];
      } else {
        sum += stoll(curr);
        curr = A[i + 1];
      }
    }
    sum += stoll(curr);
    sums.insert(sum);
  }

  cout << sums.size() << "\n";
  return 0;
}