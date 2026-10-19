/*
Since the number of towers given is only 6.
We can go with a n*n! solution since n<10

The solution is simple where its important to sort an array before using
next_permutation() We can check if the paritial array is sorted or not with
is_sorted() A thing a learned about is_sorted is it need an object comparator
and we can get it with  greater<int>() where as priority queue, sets, maps, etc
take a comparator as a type
Finally we check if we have the right answer with accumulate()
*/
#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  vector<int> A(6);
  for (auto& it : A) cin >> it;
  int b, c;
  cin >> b >> c;

  sort(A.begin(), A.end());

  do {
    if (is_sorted(A.begin(), A.begin() + 3, greater<int>()) &&
        is_sorted(A.begin() + 3, A.begin() + 6, greater<int>()) &&
        (accumulate(A.begin(), A.begin() + 3, 0) == b) &&
        (accumulate(A.begin() + 3, A.begin() + 6, 0) == c)) {
      for (int i = 0; i < 6; i++) {
        if (i) cout << ' ';
        cout << A[i];
      }
      return 0;
    }
  } while (next_permutation(A.begin(), A.end()));
  assert(false);
  return 0;
}