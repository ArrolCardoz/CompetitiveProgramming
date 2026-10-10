#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

bool checkPattern(string str, int& balls) {
  int total = 0;
  for (auto& it : str) {
    total += it - '0';
  }
  balls = (total / 2.0);
  return total % str.size(), ;
}

void solution(string str) {
  int balls;
  if (!checkPattern(str, balls)) {
    cout << string << "invalid # of balls" << endl;
  }
}

int main() {
  fastIO();

  string str;
  while (cin >> str) solution(str);
  return 0;
}