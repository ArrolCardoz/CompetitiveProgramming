#include <bits/stdc++.h>
using namespace std;

void solution(int classs, int s) {
  while (s != 0) {
    for (int i = 0; i < classs; i++) {
      int num;
      cin >> num;
      s -= num;
      if (s == 0) break;
    }
    break;
  }
  if (s >= 0)
    cout << "Jebb ";
  else
    cout << "Neibb  ";
}
int main() {
  int s, c;
  cin >> s >> c;
  solution(s, c);
}