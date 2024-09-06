#include <bits/stdc++.h>
using namespace std;

void solution(string a, string b) {
  auto ait = a.begin();
  auto bit = b.begin();
  int loop = a.size() + b.size() + 1;
  int counter = 0;
  // cout << loop << endl;
  // while (ait != a.end() - 1 || bit != b.end() - 1) {
  while (loop != counter) {
    // cout << *ait << " " << *bit << endl;
    if (bit == b.end()) {
      cout << *ait;
      ait++;
    } else if (ait == a.end()) {
      cout << *bit;
      bit++;
    } else if (*ait > *bit) {
      cout << *bit;
      bit++;
    } else {
      if ((ait != a.end())) {
        cout << *ait;
        ait++;
      }
    }
    counter++;
  }
}

int main() {
  string ann, ben;
  cin >> ann >> ben;
  sort(ann.begin(), ann.end());
  sort(ben.begin(), ben.end());

  solution(ann, ben);
}