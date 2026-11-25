/*
 XOR basis solution
References:-

https://usaco.guide/adv/xor-basis?lang=cpp
https://www.youtube.com/watch?v=EcrlZZO059M&t=6690s
https://www.youtube.com/watch?v=EcrlZZO059M&t=22907s
https://www.youtube.com/watch?v=aFScgsEopqo (random youtube video XOR basis, its
in Hindi)

I didn't understand the Gaussian Elimination way of solving it during the Friday
session, but in the end you did mention that XOR basis which is what I ended up
doing because its was much easier to understand and there was an implementation
of it in usaco

Idea:-
As explained the solution in the live stream, we check every sub array and
create a new basis everytime we are at the start of the sub array, this way we
can reuse the basis previously calculated. If we find a vector that is linearly
dependent it means that the same vector is present from i(current position) to
the end(n). So we can just add n-i in our answer since we only care about the
count of the sub array. This way we can exit early from n^2 loop. (more about
time complexity later.).

There is a special case where we have 0 which we cannot
represent it in the basis. The subarray can only include 0 if there is a pair of
it because 0 XOR i (where 'i' is any number) is not equal to 0. So the case
where 0 is with a pair with another integer is always not valid but its valid
when there is a pair of two zeros. So we need to keep track of the number of
zeros and if there is a pair we can say that a disjoint set exists among the sub
array i to n.

Time complexity:
Since n<=200'000 a O(n^2) solution is not possible. But since we know that A[i]
is upto 10^9 which is 30 bits. We need to run the second loop only up to maximum
case of 30 before finding a vector that is linearly dependent to the basis. So
the time complexity is 200'000*30*31= 186'000'000 which is fast enough for logic
operations.
 */
#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n;
  int64_t ans = 0;
  cin >> n;
  vector<int> A(n);
  for (auto& it : A) cin >> it;

  for (int i = 0; i < n; i++) {
    int xorBasis[30] = {0};  // 2^30>10^9
    int numOfZeros = 0;
    for (int j = i; j < n; j++) {
      int a = A[j];
      bool isValid = false;

      if (a == 0) {  // cannot represent 0 in basis
        numOfZeros++;
        if (numOfZeros == 2) {
          ans += n - j;
          break;
        }
      } else {
        for (int k = 29; k >= 0; k--) {
          // check MSB
          if (!((1 << k) & a)) {
            continue;
          }
          // check if basis has a bit in this dimention
          if (xorBasis[k]) {
            a ^= xorBasis[k];
            if (a == 0) break;
          } else {
            xorBasis[k] = a;
            break;
          }
        }
        if (a == 0) isValid = true;  // is linearly dependent.
      }
      if (isValid)

      {
        /*
        we add n-j because its we can add the same disjoint set from sub
        array j to n
        */
        ans += n - j;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}