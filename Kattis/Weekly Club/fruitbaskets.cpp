/*
Idea:- Pruning is necessary in this question since N>20 which is required for
brute force.
I used 2 ways to prune in my backtracking
1. Keeping track of the running sum of the basket and the remaining fruits if
remaining + sum is less than 200 then we break early
2. If sum is greater than 200 than we use the following formula
sum^2^remainingFruits+1 + remainingWeight^2^remainingFruits
I do not remember the method discussed in the lab, to get this I drew the truth
table and when ever we are adding something he repeat the truth table by n^2
plus a column of the new entry.
Since we are not adding a element in a truth table but joining 2 truth tables we
take the power of the elements we are adding(remainingWeight^2^remainingFruits),
with the sum having an extra carry of 2(sum^2^remainingFruits+1 )

Other notes- used int64 because of overflow in sum.
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int64_t backtrack(vi& A, int64_t remaining, int64_t curr, int64_t sum) {
  if (sum >= 200) {
    if (curr == -1) {
      return sum;
    }
    return (sum * (1LL << (curr + 1))) + (remaining * (1LL << (curr)));
  }
  if (curr < 0 || (sum + remaining) < 200) return 0;

  return backtrack(A, remaining - A[curr], curr - 1, sum + A[curr]) +
         backtrack(A, remaining - A[curr], curr - 1, sum);
}
int main() {
  fastIO();
  int n;
  cin >> n;
  vi A(n);
  int64_t sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum += A[i];
  }

  cout << backtrack(A, sum, n - 1, 0LL) << endl;

  return 0;
}