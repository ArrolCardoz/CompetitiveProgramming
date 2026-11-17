#include <bits/stdc++.h>
using namespace std;
#define tsdd tuple<string, double, double>

const int MAX = 600;
tsdd A[MAX];
bool cmp(const tsdd& a, const tsdd& b) {
  if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
  if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
  return get<0>(a) > get<0>(b);
}
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> get<0>(A[i]) >> get<1>(A[i]) >> get<2>(A[i]);
  }
  sort(A, A + n, cmp);
  vector<string> ans;
  double currMIN = 127 * 100 * 100;

  for (int i = 0; i < n; i++) {
    vector<string> currNames;
    double curr = 0.0;
    string firstName = get<0>(A[i]);
    currNames.push_back(firstName);
    curr += get<1>(A[i]);
    int ctr = 1, idx = 0;

    while (ctr < 4) {
      if (get<0>(A[idx]) == firstName) {
        idx++;
        continue;
      }
      curr += get<2>(A[idx]);
      ctr++;
      currNames.push_back(get<0>(A[idx]));
      idx++;
    }
    if (curr < currMIN) {
      currMIN = curr;
      ans = currNames;
    }
  }

  cout << fixed << setprecision(10) << currMIN << endl;
  for (auto& it : ans) cout << it << endl;
  return 0;
}