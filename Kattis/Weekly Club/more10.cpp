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
int getIdx(unordered_map<string, int>& wordIdx, vector<string>& words,
           string& word) {
  if (wordIdx.find(word) == wordIdx.end()) {
    wordIdx[word] = words.size();
    words.push_back(word);
  }
  return wordIdx[word];
}

int main() {
  int n;
  cin >> n;

  unordered_map<string, int> wordIdx;  // word -> index
  vector<string> words;                // index -> word

  // each statement: word indices a and b, and whether it is "is" (1) or "not"
  // (0)
  vector<int> stA, stB, stIs;

  string w1, op, w2;
  while (n--) {
    cin >> w1 >> op >> w2;
    int a = getIdx(wordIdx, words, w1);
    int b = getIdx(wordIdx, words, w2);
    stA.push_back(a);
    stB.push_back(b);
    stIs.push_back(op == "is" ? 1 : 0);
  }

  UnionFind uf(words.size() + 1);

  // step 2: rhyme merges
  unordered_map<string, int> rep3;  // last 3 chars -> a word with that ending
  for (int i = 0; i < (int)words.size(); i++) {
    string w = words[i];
    int L = w.size();

    // words of length >= 3: same last 3 chars means they rhyme
    if (L >= 3) {
      string suf = w.substr(L - 3);
      if (rep3.find(suf) == rep3.end())
        rep3[suf] = i;
      else
        uf.merge(i, rep3[suf]);
    }

    // short words: if the last 1 or 2 chars of w form a word that exists,
    // then w rhymes with that word
    for (int k = 1; k <= 2; k++) {
      if (L >= k) {
        string suf = w.substr(L - k);
        if (wordIdx.find(suf) != wordIdx.end()) uf.merge(i, wordIdx[suf]);
      }
    }
  }

  // step 3: explicit "is"
  for (int i = 0; i < (int)stA.size(); i++) {
    if (stIs[i] == 1) uf.merge(stA[i], stB[i]);
  }

  // step 4: explicit "not"
  for (int i = 0; i < (int)stA.size(); i++) {
    if (stIs[i] == 0 && uf.find(stA[i]) == uf.find(stB[i])) {
      cout << "wait what?" << endl;
      return 0;
    }
  }

  cout << "yes" << endl;
  return 0;
}