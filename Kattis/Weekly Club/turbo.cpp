/*
As stated in lab I used a fenwick tree to solve this problem
Setup:-
The fewick tree is used as an active rank of the given array
Instead of storing the array as it was given I stored as an inverse index
array(index array) so I can look up the position of required number without
needing to scan the array. This is possible only because all the numbers are
distinct.

Idea:-
Now that we have a way to get the numbers in constant time for the solution we
only have to track the start(lo) and end(hi) pointer of the array and look up
the rank with fenwick tree and get the difference from the pointer, decrement
the rank of that position which means removing the element without actually
removing it and fenwick tree updates the remaining ranks. Shrink the pointer and
alternate the pointers as stated in the problem and continue till the start
pointer < end pointer.
*/
#include <bits/stdc++.h>
using namespace std;

/*
 * Fenwick Tree
 *
 * Author: Howard Cheng
 * Reference:
 *
 *   Fenwick, P.M. "A New Data Structure for Cumulative Frequency Tables."
 *   Software---Practice and Experience, 24(3), 327-336 (March 1994).
 *
 * This code has been tested on UVa 11525 and 11610.
 *
 * Fenwick trees are data structures that allows the maintainence of
 * cumulative sum tables dynamically.  The following operations
 * are supported:
 *
 * - Initialize the tree from a list of N integers:                 O(N log N)
 *
 * - Read the cumulative sum at index 0 <= k < N:                   O(log k)
 *
 * - Read the entry at index 0 <= k < N:                            O(log N)
 *
 * - Increment/decrement an entry at index 0 <= k < N in the list:  O(log N)
 *
 * - Given a value, find an index such that the cumulative sum at
 *   that position is the value:                                    O(log N)
 *
 * The space usage is at most 2*N for N input entries.
 *
 * NOTE: it is assumed that all entries are non-negative (even after a
 *       decrement operation).
 *
 */

#include <cassert>
#include <vector>

using namespace std;

class FenwickTree {
 public:
  FenwickTree(int n = 0) : N(n), tree(n) {
    iBM = 1;
    while (iBM < N) {
      iBM *= 2;
    }
    tree.resize(iBM + 1);
    fill(tree.begin(), tree.end(), 0);
  }

  // initialize the tree with the given array of values
  FenwickTree(int val[], int n) : N(n) {
    iBM = 1;
    while (iBM < N) {
      iBM *= 2;
    }

    tree.resize(iBM + 1);
    fill(tree.begin(), tree.end(), 0);
    for (int i = 0; i < n; i++) {
      assert(val[i] >= 0);
      incEntry(i, val[i]);
    }
  }

  // increment the entry at position idx by val (use negative val for
  // decrement).  All affected cumulative sums are updated.
  void incEntry(int idx, int val) {
    assert(0 <= idx && idx < N);
    if (idx == 0) {
      tree[idx] += val;
    } else {
      do {
        tree[idx] += val;
        idx += idx & (-idx);
      } while (idx < (int)tree.size());
    }
  }

  // return the cumulative sum val[0] + val[1] + ... + val[idx]
  int cumulativeSum(int idx) const {
    assert(0 <= idx && idx < (int)tree.size());
    int sum = tree[0];
    while (idx > 0) {
      sum += tree[idx];
      idx &= idx - 1;
    }
    return sum;
  }

  // return the entry indexed by idx
  int getEntry(int idx) const {
    assert(0 <= idx && idx < N);
    int val, parent;
    val = tree[idx];
    if (idx > 0) {
      parent = idx & (idx - 1);
      idx--;
      while (parent != idx) {
        val -= tree[idx];
        idx &= idx - 1;
      }
    }
    return val;
  }

  // return the largest index such that the cumulative frequency is
  // what is given, or -1 if it is not found
  //
  int getIndex(int sum) const {
    int orig = sum;
    if (sum < tree[0]) return -1;
    sum -= tree[0];

    int idx = 0;
    int bitmask = iBM;

    while (bitmask != 0 && idx < (int)tree.size() - 1) {
      int tIdx = idx + bitmask;
      if (sum >= tree[tIdx]) {
        idx = tIdx;
        sum -= tree[tIdx];
      }
      bitmask >>= 1;
    }

    if (sum != 0) {
      return -1;
    }

    idx = min(N - 1, idx);
    return (cumulativeSum(idx) == orig) ? idx : -1;
  }

 private:
  int N, iBM;
  vector<int> tree;
};

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  // initilize
  fastIO();
  int n;
  cin >> n;
  int Rank[n];
  int A[n];
  fill(Rank, Rank + n, 1);
  FenwickTree getRankft(Rank, n);

  // input
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    input--;
    A[input] = i;
  }

  // solution
  int hi = n - 1, lo = 0;
  int total = n;
  bool swapFront = true;
  while (hi >= lo) {
    if (swapFront) {
      cout << getRankft.cumulativeSum(A[lo]) - 1 << endl;
      getRankft.incEntry(A[lo], -1);
      lo++;
      total--;
    }

    else {
      cout << total - getRankft.cumulativeSum(A[hi]) << endl;
      getRankft.incEntry(A[hi], -1);
      total--;
      hi--;
    }
    swapFront = !swapFront;
  }

  return 0;
}