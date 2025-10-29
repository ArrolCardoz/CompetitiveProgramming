#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, stages;

  cin >> n >> stages;

  int data[n][stages] = {0};
  int total = 0;

  for (int i = 0; i < stages; i++) {
    int input;
    cin >> input;
    total += input;
    data[0][i] = total;
  }

  cout << data[0][stages - 1] << endl;

  for (int num = 1; num < n; num++) {
    int input;
    for (int i = 0; i < stages; i++) {
      cin >> input;
      if (i == 0)
        data[num][0] = data[num - 1][0] + input;
      else
        data[num][i] = max(data[num - 1][i] + input, data[num][i - 1] + input);
    }
    cout << data[num][stages - 1] << endl;
  }
  return 0;
}