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
  int64_t cumulativeSum(int idx) const {
    assert(0 <= idx && idx < (int)tree.size());
    int64_t sum = tree[0];
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
  vector<int64_t> tree;
};

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();

  int size, n;
  cin >> size >> n;
  int currJemIdx[size];
  vector<int> jems(6, 0);
  vector<FenwickTree> ft(6, FenwickTree(size));

  for (auto& it : jems) {
    cin >> it;
  }

  string jemsOrder;
  cin >> jemsOrder;

  int ctr = 0;
  for (auto& it : jemsOrder) {
    int idx = it - '1';
    currJemIdx[ctr] = idx;
    ft[idx].incEntry(ctr, 1);
    ctr++;
  }

  // solution

  while (n--) {
    int caseNum;
    cin >> caseNum;
    switch (caseNum) {
      case 1: {
        int idx, newJem;
        cin >> idx >> newJem;
        idx--;
        newJem--;
        int oldJem = currJemIdx[idx];
        ft[newJem].incEntry(idx, 1);
        ft[oldJem].incEntry(idx, -1);
        currJemIdx[idx] = newJem;
        break;
      }
      case 2: {
        int jemIdx, newValue;
        cin >> jemIdx >> newValue;
        jemIdx--;
        jems[jemIdx] = newValue;
        break;
      }
      case 3: {
        int a, b;
        cin >> a >> b;
        int64_t total = 0;
        a -= 2;
        b--;
        for (int i = 0; i < 6; i++) {
          int64_t lb = 0, hb = 0;
          if (a >= 0) {
            lb = ft[i].cumulativeSum(a);
          }
          hb = ft[i].cumulativeSum(b);
          total += (hb - lb) * jems[i];
        }
        cout << total << endl;
      }
    }
  }

  return 0;
}