#include <bits/stdc++.h>
using namespace std;

/*
Idea :-
Since all the ingredients are distict we can just add up the sets they
are currently in (initially everyone is in a set by itself) and
if |ingredients| < |the set we added up|
by pigon hole principle we have more than requied ingredients.
Solution:-
 As stated in class I used union find data structure because of the
way we add up the sets. In order to get the frequency I maintained a frequency
table (A).
I modified the UnionFind class code where when we are merging and initilizing I
change 'A' accordingly.
Finally for every 'N' I check if the recipe is valid or not in "isValid"
question and return the number of times its valid.
For isValid function I kept track of current index in currSet class but I have
to keep track and insert the index of set only once because I am adding up the
total while inserting. Since find in set is constant I can do it otherwise I can
it and add up the total later.
Finally if the size if equal I loop through the set and merge all the sets with
the first one.

*/

const int MAX_CASE = 500500;

int A[MAX_CASE];
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
      A[i]++;  // initializing A
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
        A[res1] += A[res2];  // adding previous parent
      } else {
        uf[res1].p = res2;
        A[res2] += A[res1];  // adding previous parent

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

bool isValid(vector<int>& ingredients, UnionFind& uf) {
  unordered_set<int> currSet;
  int total = 0;
  for (int i = 0; i < (int)ingredients.size(); i++) {
    int currIdx = uf.find(ingredients[i]);

    if (currSet.find(currIdx) == currSet.end()) {
      total += A[currIdx];
      currSet.insert(currIdx);
    }
  }
  if (total != (int)ingredients.size()) return false;  // its not equal

  // join the remaining sets
  int joinSet = *currSet.begin();
  for (auto i = next(currSet.begin()); i != currSet.end(); i++) {
    uf.merge(joinSet, *i);
  }
  return true;
}

int main() {
  UnionFind UF(500'001);
  int n, ans = 0;
  cin >> n;

  while (n--) {
    int num;
    cin >> num;
    vector<int> ingredients(num);
    for (auto& it : ingredients) cin >> it;
    if (isValid(ingredients, UF)) ans++;
  }
  cout << ans << endl;

  return 0;
}