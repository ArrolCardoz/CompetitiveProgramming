#include <bits/stdc++.h>
using namespace std;
int soultion(int num) {
  int n1 = 1, n2 = 1, n = 2, temp;
  map<int, int> data;
  while (true) {
    temp = n1;
    n1 = (n1 + n2) % num;
    n2 = temp;

    // cout << n << ' ' << n1 << endl;

    if (data.find(n1) == data.end())
      data[n1] = n;
    else
      return data[n1];
    // cout << data[temp] << endl;
    n++;
    // cout << n << endl;
  }
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    cout << soultion(num) << endl;
  }
  return 0;
}