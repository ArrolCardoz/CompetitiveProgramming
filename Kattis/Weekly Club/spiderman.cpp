/*
There are only 40*1000 states in this problem
So we can have 2 tables one for memoization and other to store the choice used
to reconstruct the optimal answer

Idea:- The base case of dp only finds if the answer is possible or not. The only
other value we are returning is maximum of the current height and the choices we
have while minimizing the height of our choice.
If the answer is not possible we return infinity(oo) otherwise 0.
If the answer is possible we save the choice of that state in array 'P' since we
only need one solution we can store the choices as 1's and 0's instead of
bitmask.
The reconstruct function traces the answer array (P) and prints the choices.
 */
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50;
const int oo = 1005;
int memo[MAX_N][oo];
int P[MAX_N][oo];
int A[MAX_N];
int n;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int dp(int idx, int currH) {
  // base case
  if (idx == n && currH != 0) return oo;
  if (idx == n && currH == 0) return 0;
  int& ans = memo[idx][currH];
  if (ans != -1) return ans;

  int up = dp(idx + 1, currH + A[idx]);
  if (up != oo) P[idx][currH] = 1;  // update answer list

  if (currH - A[idx] < 0) return ans = up;  // if cannot go down

  int down = dp(idx + 1, currH - A[idx]);

  if (down < up) {  // if down is more efficient update the answer list
    P[idx][currH] = 0;
  }
  return ans = max(currH,
                   min(up, down));  // "min" checks if current path is
                                    // possible or not. Where as "max" keeps
                                    // track of the maximum height so far.
}

void reconstruct() {
  int currH = 0;
  for (int i = 0; i < n; i++) {
    if (P[i][currH]) {
      cout << 'U';
      currH += A[i];
    } else {
      cout << 'D';
      currH -= A[i];
    }
  }
  cout << endl;
}

void solution() {
  cin >> n;
  memset(memo, -1, sizeof(memo));

  for (int i = 0; i < n; i++) cin >> A[i];

  int ans = dp(0, 0);
  if (ans == oo)
    cout << "IMPOSSIBLE" << endl;
  else
    reconstruct();
}

int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}