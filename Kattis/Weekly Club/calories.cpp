#include <bits/stdc++.h>
using namespace std;

// failed attempt 2+hrs
bool solution() {
  int var = -1, fat;
  int problemTotal = 0, totalCal = 0, totalPercentage = 0, problemFat = 0,
      total = 0;
  char ch;
  int calorieConvert[] = {9, 4, 4, 4, 7};
  while (true) {
    cout << 2 << endl;

    for (int i = 0; i < 5; i++) {
      cout << 1 << endl;

      cin >> var >> ch;
      if (i == 0) {
        if (var == NULL) {
          break;
        }
        fat = var;
      }
      if (ch == '%')
        totalPercentage += var;
      else if (ch == 'C')
        totalCal += var;
      else
        totalCal += var * calorieConvert[i];
    }

    if (total == 0) break;
    if (totalPercentage != 0) {
      int percent = 100 - totalPercentage;
      total = totalCal / percent;
    } else if (totalPercentage = 0)
      total = totalCal;

    problemTotal += total;
    problemFat += (fat * 100) / total;
  }
  if (problemTotal == 0)
    return false;
  else {
    cout << problemFat * 100 / problemTotal << endl;
    return true;
  }
}

int main() {
  while (solution()) {
  }
  return 0;
}