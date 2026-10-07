#include <bits/stdc++.h>
using namespace std;

const int MAX_CASE_BUFFER = 500;
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
    int size;
  };

 public:
  UnionFind(int n) {  // constructor
    howMany = n;
    uf = new UF[howMany];
    for (int i = 0; i < howMany; i++) {
      uf[i].p = i;
      uf[i].rank = 0;
      uf[i].size = 1;
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
        uf[res1].size += uf[res2].size;
      } else {
        uf[res1].p = res2;
        uf[res2].size += uf[res1].size;
        if (uf[res1].rank == uf[res2].rank) uf[res2].rank++;
      }
      return true;
    }
    return false;
  }

  int getSize(int x) { return uf[find(uf, x)].size; }

  int getGroups() {
    int groups = 0;
    for (int i = 0; i < howMany; i++) {
      if (uf[i].p == i) groups++;
    }
    return groups;
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

int randomValue(int& r, int& a, int& b, int& c) { return r = (r * a + b) % c; }

void solution(int n, int r, int a, int b, int c) {
  int x, y;
  UnionFind uf(n);
  unordered_set<int> groupCtr;
  map<int, int, greater<int>> freqTable;
  for (int i = 0; i < n; i++) {
    do {
      x = randomValue(r, a, b, c) % n;
      y = randomValue(r, a, b, c) % n;
    } while (x == y);

    uf.merge(x, y);
  }

  for (int i = 0; i < n; i++) {
    freqTable[uf.getSize(i)]++;
  }
  cout << uf.getGroups();
  for (auto& [m, n] : freqTable) {
    cout << ' ';

    if (m > 0 && n / m > 1) {
      cout << m << 'x' << n / m;
    } else
      cout << m;
  }

  cout << endl;
}

int main() {
  int n, r, a, b, c;
  while (cin >> n >> r >> a >> b >> c) solution(n, r, a, b, c);
  return 0;
}