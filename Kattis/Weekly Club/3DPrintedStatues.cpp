#include <bits/stdc++.h>
using namespace std;
int solution(int n) {
  int printers = 1;
  int days = 0;
  while (printers < n) {
    printers = printers * 2;

    days++;
    //  cout << printers << endl;
  }
  days++;
  return days;
}

int main() {
  int n;
  cin >> n;
  cout << solution(n);
  return 0;
}