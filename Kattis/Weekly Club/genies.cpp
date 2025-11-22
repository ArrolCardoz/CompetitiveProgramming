#include <bits/stdc++.h>
using namespace std;

bool solution(int w, int k, int c, int total) {
  //   cerr << total << endl;
  if (w - c < 1) {
    total += w;
    // cerr << total << endl;

    return (total >= k);
  } else {
    total += w - 1;
    w -= c;
    return solution(w, k, c, total);
  }
  assert(false);
}

int main() {
  int w, k, c;
  cin >> w >> k >> c;
  if (w < k) {
    cout << "no" << endl;

  } else if (w == k) {
    cout << "yes" << endl;
  } else {
    if (solution(k, w, c, 0))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}