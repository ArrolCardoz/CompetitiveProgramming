#include <bits/stdc++.h>
using namespace std;

int main() {
  int A[3];
  cin >> A[0] >> A[1] >> A[2];
  sort(A, A + 3);
  // for (auto &it : A) cout << it << endl;
  int minDiff1 = A[1] - A[0];
  int minDiff2 = A[2] - A[1];
  // cout << minDiff1 << " " << minDiff2;
  if (minDiff1 == minDiff2)
    cout << A[0] - minDiff1;
  else {
    if (minDiff1 < minDiff2)
      cout << A[1] + minDiff1;
    else
      cout << A[0] + minDiff2;
  }
}