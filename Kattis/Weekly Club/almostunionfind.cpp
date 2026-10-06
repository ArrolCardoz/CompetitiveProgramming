#include <bits/stdc++.h>
using namespace std;

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind
int N = 0;
class UnionFind {
  struct UF {
    int p;
    int rank;
    int count;
    int64_t sum;
    int id;
  };

 public:
  UnionFind(int n) {  // constructor
    howMany = n;
    uf = new UF[howMany];
    for (int i = 0; i < howMany; i++) {
      uf[i].p = i;
      uf[i].rank = 0;
      uf[i].count = 1;
      uf[i].sum = i;
      uf[i].id = i;
    }
  }

  ~UnionFind() { delete[] uf; }

  int find(int x) { return find(uf, uf[x].id); }  // for client use

  bool merge(int x, int y) {
    int res1, res2;
    res1 = find(uf, uf[x].id);
    res2 = find(uf, uf[y].id);

    if (res1 != res2) {
      if (uf[res1].rank > uf[res2].rank) {
        uf[res2].p = res1;
        uf[res1].count += uf[res2].count;
        uf[res1].sum += uf[res2].sum;

      } else {
        uf[res1].p = res2;
        uf[res2].count += uf[res1].count;
        uf[res2].sum += uf[res1].sum;

        if (uf[res1].rank == uf[res2].rank) {
          uf[res2].rank++;
        }
      }

      return true;
    }
    return false;
  }

  void print(int x) {
    int res1 = find(uf, uf[x].id);
    cout << uf[res1].count << ' ' << uf[res1].sum << endl;
  }

  bool move(int x, int y) {
    int res1, res2;
    N++;
    res1 = find(uf, uf[x].id);
    res2 = find(uf, uf[y].id);
    if (res1 != res2) {
      uf[x].id = N;
      uf[res1].count--;
      uf[res1].sum -= x;
      uf[N].rank = 0;
      uf[N].p = N;
      uf[N].count = 1;
      uf[N].sum = x;
      uf[N].id = N;

      merge(N, y);
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

void solution(int size, int n) {
  N = size;
  UnionFind uf(size + n + 500);
  while (n--) {
    int caseNum, a, b;
    cin >> caseNum;
    if (caseNum == 1) {
      cin >> a >> b;
      uf.merge(a, b);
    } else if (caseNum == 2) {
      cin >> a >> b;
      uf.move(a, b);
    } else {
      cin >> a;
      uf.print(a);
    }
  }
}

int main() {
  int size, n;
  while (cin >> size >> n) {
    solution(size, n);
  }
  return 0;
}