#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int counter = 0;
  while (n--) {
    int input;
    cin >> input;
    if (input <= m) {
      cout << "It hadn't snowed this early in " << counter << " years!" << endl;
      return 0;
    }
    counter++;
  }
  cout << "It had never snowed this early!" << endl;
  return 0;
}