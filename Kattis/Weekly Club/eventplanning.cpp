#include <bits/stdc++.h>
using namespace std;

int main() {
  int participants, budget, hotels, weeks, free;
  int minimum = INT_MAX, cost, run = 1;
  cin >> participants >> budget >> hotels >> weeks;
  for (int j = 0; j < hotels; j++) {
    cin >> cost;
    if (minimum > cost && cost * participants <= budget)
      run = 1;
    else
      run = 0;
    for (int i = 0; i < weeks; i++) {
      cin >> free;
      if (!run) continue;
      if (free >= participants) {
        run = 0;
        minimum = cost;
      }
    }
  }
  if (minimum == INT_MAX) {
    cout << "stay home" << endl;
    return 0;
  }
  cout << minimum * participants << endl;
  return 0;
}