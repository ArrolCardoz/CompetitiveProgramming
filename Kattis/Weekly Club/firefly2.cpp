#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h;
  int idxTop = 0, idxBottom = 0;

  cin >> n >> h;
  int ctr = n / 2;

  vector<int> total(h), bottom, top;
  bottom.reserve(n / 2);
  top.reserve(n / 2);
  n /= 2;

  while (n--) {
    int num;
    cin >> num;
    bottom.push_back(num);
    cin >> num;
    top.push_back(h - num);
  }

  sort(begin(bottom), end(bottom));
  sort(begin(top), end(top));
  //   for (auto& it : top)  // cerr << it << endl;

  for (int i = 0; i < h; i++) {
    while (bottom[idxBottom] == i) {
      ctr--;
      idxBottom++;
    }
    // cerr << i << ' ' << ctr << endl;
    while (top[idxTop] == i) {
      idxTop++;
      ctr++;
    }
    // cerr << i << ' ' << ctr << endl;

    total[i] = ctr;
  }
  //   for (auto& it : total)  // cerr << it << endl;
  int minNum = *min_element(begin(total), end(total));
  ctr = count(total.begin(), total.end(), minNum);
  cout << minNum << endl << ctr << endl;

  return 0;
}