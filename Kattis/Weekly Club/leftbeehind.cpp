#include <bits/stdc++.h>
// gameDev day 2
using namespace std;

int main() {
  int sweet, sour;
  while (cin >> sweet >> sour) {
    if (sweet == 0 && sour == 0) {
      break;
    }
    if (sweet + sour == 13)
      cout << "Never speak again." << endl;
    else if (sweet == sour)
      cout << "Undecided." << endl;
    else if (sweet > sour)
      cout << "To the convention." << endl;
    else
      cout << "Left beehind." << endl;
  }
  return 0;
}