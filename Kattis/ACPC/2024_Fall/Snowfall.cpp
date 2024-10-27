#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;

  int snow = 0;
  int day;
  int na;
  for (int i = 0; i < n; i++) {
    cin >> day;
    if (day) {
      cin >> na;
      snow -= na;
      if (snow < 0) snow = 0;
    } else {
      cin >> na;
      snow += na;
    }
  }
  cout << snow;
}

int main() {
  solution();
  return 0;
}