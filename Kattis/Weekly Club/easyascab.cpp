/*
There are two ways to solve it one of by topological sort and other
is by Transitive Closure of a Graph (Floyd Warshall Algorithm)

This is the Transitive Closure solution as explained in the lab.

Solution:- Since the words are given in lexicographical order, we need to check
the first different word and store in the in adjacent matrix (A).

Once we have the adjacent matrix we can get the transitive closure and modify A.
Finally we need to check if cycle exists and count the number of 1's and place
the character in the answer vector respectively.

Other references:-
https://www.geeksforgeeks.org/dsa/transitive-closure-of-a-graph/
 */
#include <bits/stdc++.h>
using namespace std;
bool A[26][26] = {};
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  char lastLetter;
  int N;
  cin >> lastLetter >> N;
  int n = lastLetter - 'a' + 1;

  vector<string> words(N);
  for (auto& word : words) cin >> word;

  for (int w = 0; w + 1 < N; w++) {
    const string& first = words[w];
    const string& second = words[w + 1];

    int minLen = min(first.size(), second.size());
    int pos = 0;
    while (pos < minLen && first[pos] == second[pos]) pos++;

    if (pos < minLen) {
      A[first[pos] - 'a'][second[pos] - 'a'] = 1;
    } else if (first.size() > second.size()) {
      // second is a prefix of first but is listed after it
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  // transitive closure
  for (int k = 0; k < 26; k++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++) A[i][j] |= A[i][k] && A[k][j];

  // cycle check
  for (int letter = 0; letter < n; letter++) {
    if (A[letter][letter]) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  string answer(n, '?');
  for (int letter = 0; letter < n; letter++) {
    int lettersAfter = 0;  // number of 1s in this letters row
    for (int other = 0; other < n; other++) lettersAfter += A[letter][other];

    int position = n - 1 - lettersAfter;
    if (answer[position] != '?') {  // two letters in same spot
      cout << "AMBIGUOUS" << endl;
      return 0;
    }
    answer[position] = 'a' + letter;
  }

  cout << answer << endl;
  return 0;
}