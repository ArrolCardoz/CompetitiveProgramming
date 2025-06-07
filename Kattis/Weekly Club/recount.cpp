#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> votes;
  string str;
  int winner = 0, tie = 0;
  string winnerName;
  while (true) {
    getline(cin, str);
    if (str == "***") break;
    votes[str]++;
  }
  for (auto& [n, v] : votes) {
    if (v > winner) {
      winner = v;
      winnerName = n;
      tie = 1;
      //   cout << n << endl;
    } else if (v == winner) {
      tie++;
      //   cout << n << "TIE" << endl;
    }
  }
  //   cout << tie << ' ' << winner << endl;
  if (tie > 1)
    cout << "Runoff!" << endl;
  else
    cout << winnerName << endl;
  return 0;
}