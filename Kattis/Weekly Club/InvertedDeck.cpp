#include <bits/stdc++.h>
using namespace std;

int solution() {
  int n;
  cin >> n;
  int numInc = 1;
  int numDec = 0;
  int prevNum = 1;
  int decPtrBegin;
  int decPtrEnd;
  bool isIncreasing = true;

  vector<int> num;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (i == 0) {
      prevNum = temp;
      continue;
    }
    if ((isIncreasing && prevNum <= temp) ||
        (!isIncreasing && prevNum >= temp)) {
      prevNum = temp;
      continue;
    } else if (isIncreasing && prevNum >= temp) {
      isIncreasing = false;

      numDec++;
      if (numDec > 1) {
        cout << "impossible";
        break;
      }
    }
  }
}