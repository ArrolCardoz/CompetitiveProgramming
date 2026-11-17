#include <bits/stdc++.h>
using namespace std;
int A[100'500];
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n, k;
  cin >> n >> k;
  deque<int> dq;
  int maxSize = -1;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    while (!dq.empty() && (A[i] - dq.front()) >= 1000) {
      dq.pop_front();
    }
    dq.push_back(A[i]);

    maxSize = max(maxSize, (int)dq.size());
  }
  cout << (maxSize + k - 1) / k;
  return 0;
}