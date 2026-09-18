#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  int total = 0, currMax = 0, idx = 0, currIdx = 0;
  bool tie = false;
  while (n--) {
    int input;
    cin >> input;
    total += input;
    if (input > currMax) {
      tie = false;
      currIdx = idx + 1;
      currMax = input;
    } else if (input == currMax)
      tie = true;
    idx++;
  }
  //   cerr << total << ' ' << currMax * 2 << endl;
  if (tie) {
    cout << "no winner" << endl;
  } else {
    if (total >= currMax * 2) {
      cout << "minority winner ";
    } else
      cout << "majority winner ";
    cout << currIdx << endl;
  }
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}