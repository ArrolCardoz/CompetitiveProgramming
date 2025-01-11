#include <climits>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a, b;
  int highest = 0;
  int lowest = INT_MAX;
  cin >> lowest >> highest;
  n--;
  while (n--) {
    cin >> a >> b;
    if (lowest > b || a > highest) {
      cout << "bad news" << endl;
      return 0;
    }
    if (lowest < a) lowest = a;
    if (highest > b) highest = b;
  }
  cout << (highest - lowest) + 1 << " " << lowest << endl;
  return 0;
}