#include <bits/stdc++.h>
using namespace std;

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
      } else {
        uf[res1].p = res2;
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

int getID(string str, map<string, int> id) {
  if (id.find(str) == id.end()) {
    int size1 = id.size();
    id[str] = size1;
    return size1;
  }
  return id[str];
}

void solution() {
  int n;
  cin >> n;

  UnionFind uf(2 * n);
  map<string, int> nameID;
  vector<int> groupSize(2 * n, 1);
  string str1, str2;
  int id1, id2;
  for (int i = 0; i < n; i++) {
    cin >> str1 >> str2;
    id1 = getID(str1, nameID);
    id2 = getID(str2, nameID);
    uf.merge(id1, id2);
    groupSize[uf.find(id1)]++;
    cout << groupSize[id1] << endl;
  }
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}