#include <iostream>
#include <string>
using namespace std;

int main() {
  int numA = 1, numB = 0, n, tempA, tempB;
  cin >> n;
  while (n--) {
    tempA = numB;
    tempB = numA + numB;
    numB = tempB;
    numA = tempA;
  }
  cout << numA << ' ' << numB << endl;
  return 0;
}