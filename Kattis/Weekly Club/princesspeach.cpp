#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int counter = 0;
  int arr[n] = {0};
  for (int i = 0; i < m; i++) {
    int input;
    cin >> input;
    if (arr[input] == 0) counter++;
    arr[input] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (!arr[i]) cout << i << endl;
  }
  cout << "Mario got " << counter << " of the dangerous obstacles." << endl;
  return 0;
}