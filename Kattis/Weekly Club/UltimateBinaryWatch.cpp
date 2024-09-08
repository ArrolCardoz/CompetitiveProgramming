#include <bits/stdc++.h>
using namespace std;

int main() {
  int Binary[] = {8, 4, 2, 1};
  int time;
  int hour, second;
  cin >> time;
  hour = time / 100;
  second = time % 100;
  int hourTen = hour / 10;
  int hourUnit = hour % 10;
  int minTen = second / 10;
  int minUnit = second % 10;

  for (int i = 0; i < 4; i++) {
    // cout << " ======== " << hourTen << endl;

    if (i >= 1) cout << endl;

    if (hourTen >= Binary[i]) {
      hourTen -= Binary[i];
      cout << "* ";
    } else
      cout << ". ";
    if (hourUnit >= Binary[i]) {
      hourUnit -= Binary[i];
      cout << "* ";
    } else
      cout << ". ";

    cout << "  ";

    if (minTen >= Binary[i]) {
      minTen -= Binary[i];
      cout << "* ";
    } else
      cout << ". ";
    if (minUnit >= Binary[i]) {
      minUnit -= Binary[i];
      cout << "*";
    } else
      cout << ".";
  }
  return 0;
}