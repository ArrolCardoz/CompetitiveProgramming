#include <bits/stdc++.h>
using namespace std;
// As stated in class I used arrays instead of varibles to represent the data
// which lead to reusing code with loops instead of rewritting code for every
// person.
// I made the following tables--
// guess -> the guess pattern
// mod -> size of the guess pattern used to take modulus in a loop
// name -> the name of the person
//---------------------------------------------------------------------------
// solution
// the solution is checking if the guess matches and I'm looping through the
// guess by taking modulo of the guess string size
// Finally I get the max and print out the name who matches the max answer

vector<string> guess = {{"ABC"}, {"BABC"}, {"CCAABB"}};
vector<int> mod = {3, 4, 6};
vector<string> name = {"Adrian", "Bruno", "Goran"};

int main() {
  // input
  int n;
  string input;
  vector<int> ans(3, 0);
  cin >> n >> input;

  // solution
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if ((guess[j][i % mod[j]]) == input[i]) {
        ans[j]++;
      }
    }
  }

  // output
  int maxAns = *max_element(ans.begin(), ans.end());
  cout << maxAns << endl;
  for (int i = 0; i < 3; i++) {
    if (ans[i] == maxAns) cout << name[i] << endl;
  }

  return 0;
}