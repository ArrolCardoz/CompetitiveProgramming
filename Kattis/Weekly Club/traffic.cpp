#include <bits/stdc++.h>
using namespace std;
// idk
int main() {
  int car1, car2, distance;
  cin >> car1 >> car2;

  if (car1 > car2) {
    car2 += 4;
    distance = car1 - car2;
  } else {
    car1 += 4;
    distance = car2 - car1;
  }

  int n;
  int maxStop = 0;
  vector<int> c1;
  vector<int> c2;
  int a, start = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (start) {
      c1.push_back(a);
      start = 0;
    } else {
      if (maxStop < a) maxStop = a;
      c1.push_back(a);
      start = 1;
    }
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (start) {
      c2.push_back(a);
      start = 0;
    } else {
      if (maxStop < a) maxStop = a;
      c2.push_back(a);
      start = 1;
    }
  }

  for (int i = 0; i < maxStop; i++) {
  }

  return 0;
}