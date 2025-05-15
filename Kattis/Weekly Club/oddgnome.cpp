#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    int max;
    int input;

    bool gotAns = 0;
    cin >> input;
    max = input;
    max++;
    for (int i = 1; i <= num - 1; i++) {
      cin >> input;
      if (input != max)
        cout << i + 1 << endl;
      else
        max++;
    }
  }
  return 0;
}