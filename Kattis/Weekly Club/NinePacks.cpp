#include <bits/stdc++.h>
using namespace std;

void solution() {
  int numHotdog, numBread;
  map<int, int> hotdogs;
  map<int, int> hotdogsCopy;

  map<int, int> bread;
  map<int, int> breadCopy;

  cin >> numHotdog;
  int a;
  for (int i = 0; i < numHotdog; i++) {
    cin >> a;
    hotdogs[a]++;
  }
  cin >> numBread;
  for (int i = 0; i < numBread; i++) {
    cin >> a;
    bread[a]++;
  }
  hotdogsCopy = hotdogs;
  breadCopy = bread;
}