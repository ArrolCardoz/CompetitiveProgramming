#include <bits/stdc++.h>
using namespace std;

const int MAX_TEST_CASE = 300'500;
int A[2][MAX_TEST_CASE];

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind

class UnionFind {
  struct UF {
    int p;
    int rank;
  };

 public:
  UnionFind(int n) {  // constructor
    howMany = n;
    uf = new UF[howMany];
    for (int i = 0; i < howMany; i++) {
      uf[i].p = i;
      uf[i].rank = 0;
      A[0][i]++;
      A[1][i] = 0;
    }
  }

  ~UnionFind() { delete[] uf; }

  int find(int x) { return find(uf, x); }  // for client use

  bool merge(int x, int y) {
    int res1, res2;
    res1 = find(uf, x);
    res2 = find(uf, y);
    if (res1 != res2) {
      if (uf[res1].rank > uf[res2].rank) {
        uf[res2].p = res1;
        A[0][res1] += A[0][res2];
        A[1][res1] += A[1][res2];

      } else {
        uf[res1].p = res2;
        A[0][res2] += A[0][res1];
        A[1][res2] += A[1][res1];
        if (uf[res1].rank == uf[res2].rank) {
          uf[res2].rank++;
        }
      }

      return true;
    }
    return false;
  }

 private:
  int howMany;
  UF* uf;

  int find(UF uf[], int x) {  // recursive funcion for internal use
    if (uf[x].p != x) {
      uf[x].p = find(uf, uf[x].p);
    }
    return uf[x].p;
  }
};
int main() {
  int tables, items;
  cin >> items >> tables;
  UnionFind uf(tables + 1);
  while (items--) {
    int a, b;
    cin >> a >> b;
    uf.merge(a, b);

    int curr = uf.find(a);
    if (A[0][curr] >= A[1][curr] + 1) {
      cout << "LADICA" << endl;
      A[1][curr]++;

    } else
      cout << "SMECE" << endl;
  }

  return 0;
}