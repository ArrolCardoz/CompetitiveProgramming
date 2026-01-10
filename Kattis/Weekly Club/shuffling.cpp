#include <bits/stdc++.h>
using namespace std;

void shiffleIn(string& currentString, string& initialString, int& moves) {
  if (currentString == initialString && moves > 0) return;
}

int main() {
  int n;
  cin >> n;
  string mode;
  string initialString = "";
  //   string s = 'a';
  for (int i = 0; i < n; i++) initialString += 'A' + i;
  cout << initialString << endl;

  if (mode == "in") shiffleIn(initialString, initialString, 0);
  return 0;
}