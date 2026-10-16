#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solution() {
  vector<int64_t> A(12);
  for (auto& it : A) cin >> it;
  int ans = 0;
  for (int start = 1; start < 11; start++) {
    int64_t mn = 127 * 100 * 100;

    for (int end = start; end < 11; end++) {
      mn = min(mn, A[end]);

      if (A[start - 1] < mn && mn > A[end + 1]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  fastIO();
  int n;
  cin >> n;
  while (n--) {
    int caseNum;
    cin >> caseNum;
    cout << caseNum << ' ';
    solution();
  }
  return 0;
}