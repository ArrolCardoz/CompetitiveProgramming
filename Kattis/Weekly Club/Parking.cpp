#include <bits/stdc++.h>
using namespace std;
vector<int> grid[200];

void solution() {
  auto end = grid->end();
  auto begin = grid->begin();
  int a, b, c;
  int arrive, depart;
  for (int i = 3; i > 0; i--) {
    cin >> arrive >> depart;
    for (int j = arrive; j < depart; j++) {
      grid[arrive]++;
    }
  }
  int one, two, three;

  one = count(begin, end, 1);
  two = count(begin, end, 2);
  three = count(begin, end, 3);
}

int main() { return 0; }