#include <bits/stdc++.h>
using namespace std;

int main() {
  double GunnarChance = 0, EmmaChance = 0;
  double a, b;

  for (double i = 0; i < 2; i++) {
    cin >> a >> b;
    double side = b - a + 1;
    float temp = 0;

    for (int i = a; i <= b; i++) temp += i;
    cerr << temp / side << endl;

    GunnarChance += temp / side;
  }
  for (double i = 0; i < 2; i++) {
    cin >> a >> b;

    double side = b - a + 1;
    float temp = 0;
    for (int i = a; i <= b; i++) temp += i;
    cerr << temp / side << endl;

    EmmaChance += temp / side;
  }
  cerr << EmmaChance << ' ' << GunnarChance << endl;
  if (EmmaChance == GunnarChance)
    cout << "Tie" << endl;
  else if (EmmaChance > GunnarChance)
    cout << "Emma" << endl;
  else
    cout << "Gunnar" << endl;
  return 0;
}