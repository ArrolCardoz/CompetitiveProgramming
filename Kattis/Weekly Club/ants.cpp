#include <bits/stdc++.h>
using namespace std;
void solution(vector<int>& minV, vector<int>& maxV) {
  int l, n;
  cin >> l >> n;
  bool isZero = false;
  if (n == 0) {
    isZero = true;
    minV.push_back(0);
    maxV.push_back(0);
  }
  int half = l;
  int input = 0, min = 0, max = 0;

  for (int i = 0; i < n; i++) {
    cin >> input;
    if (input == 0) {
      isZero = true;
      minV.push_back(0);
      maxV.push_back(0);
    }
    if (input * 2 > half) {
      // cout << min << "<" << l - input << endl;

      if (l - input > min) min = l - input;
      if (input > max) max = input;
    }

    else {
      if (input > min) min = input;
      if ((l - input) > max) max = l - input;
    }
    // cout << min << "<" << l - input << endl;
  }
  //   if (!isZero) {
  //     minV.push_back(min);
  //     maxV.push_back(max);
  //   }
  cout << min << " " << max << endl;
  ;
}

int main() {
  int n;
  vector<int> min;
  vector<int> max;
  cin >> n;
  int counter = 0;
  while (counter != n) {
    solution(min, max);
    counter++;
  }

  //   for (int i = 0; i < n; i++) {
  //     cout << min[i] << ' ' << max[i] << endl;

  return 0;
}
