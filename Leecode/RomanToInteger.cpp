#include <bits/stdc++.h>
using namespace std;
int romanToInteger(string s) {
  map<char, int> roman;
  roman['I'] = 1;
  roman['V'] = 5;
  roman['X'] = 10;
  roman['L'] = 50;
  roman['C'] = 100;
  roman['D'] = 500;
  roman['M'] = 1000;

  int total = 0;

  for (auto it = s.end() + 1; it >= s.begin(); it--) {
    auto loop = it;
    int current = roman[*it];
    int temp = roman[*--it];

    if (temp < current && it != (s.end())) {
      total = (current - temp) + total;
      loop--;

    } else
      total = current + total;

    it = loop;
  }
  return total;
}

int main() {
  cout << romanToInteger("IV");
  return 0;
}