#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<string, int> unitId = {
      {"thou", 0},  {"th", 0}, {"inch", 1},    {"in", 1},
      {"foot", 2},  {"ft", 2}, {"yard", 3},    {"yd", 3},
      {"chain", 4}, {"ch", 4}, {"furlong", 5}, {"fur", 5},
      {"mile", 6},  {"mi", 6}, {"league", 7},  {"lea", 7}};
  unordered_map<int, int> unitConvertTo = {{1, 1000}, {2, 12}, {3, 3}, {4, 22},
                                           {5, 10},   {6, 8},  {7, 3}};
  double n;
  int u1, u2;
  string unit1, unit2, in;
  cin >> n >> unit1 >> in >> unit2;
  u1 = unitId[unit1];
  u2 = unitId[unit2];
  if (u1 == u2) {
    cout << setprecision(10) << fixed << n << endl;

  } else if (u1 > u2) {
    while (u1 > u2) {
      n *= unitConvertTo[u1];
      u1--;
    }
    cout << setprecision(10) << fixed << n << endl;

  } else {
    while (u1 < u2) {
      n /= unitConvertTo[u1 + 1];
      u1++;
    }
    cout << setprecision(10) << fixed << n << endl;
  }
  return 0;
}