#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> r1, vector<int> r2, int num) {
  vector<int> t1, t2;
  for (int i = 0; i < (int)r1.size(); i++) {
    if (r1[i] > num) t1.push_back(r1[i]);
  }
  for (int i = 0; i < (int)r1.size(); i++) {
    if (r2[i] > num) t1.push_back(r2[i]);
  }

  if ((t1.size() > 1) && t1[0] != t1[1]) return false;
  if ((t2.size() > 1) && t2[0] != t2[1]) return false;
  if ((t1.size() > 1) && t1[t1.size() - 1] != t1[t1.size() - 2]) return false;
  if ((t2.size() > 1) && t2[t2.size() - 1] != t2[t2.size() - 2]) return false;
  for (auto& it : t1) cerr << it << endl;
  for (auto& it : t2) cerr << it << endl;

  for (int i = 1; i < (int)t1.size() - 1; i++) {
    cerr << t1[i] << ' ';
    if (t1[i] != t1[i - 1] || (t1[i] != t1[i + 1])) {
      cerr << t1[i] << ' ' << t1[i - 1] << ' ' << t1[i + 1] << endl;
      cerr << "FAUL1 " << t1[i] << endl;

      return false;
    }
  }
  cerr << endl;
  for (int i = 1; i < (int)t2.size() - 1; i++) {
    cerr << t2[i] << ' ';

    if (t2[i] != t2[i - 1] || (t2[i] != t2[i + 1])) {
      cerr << "FAUL2 " << num << endl;

      return false;
    }
  }
  cerr << endl;
  cerr << "PASSSSS " << num << endl;
  return true;
}

int main() {
  int n;
  int maximum = 0;
  cin >> n;
  vector<int> r1(n), r2(n);
  for (int i = 0; i < n; i++) {
    cin >> r1[i];
    maximum = max(maximum, r1[i]);
  }
  for (int i = 0; i < n; i++) {
    cin >> r2[i];
    maximum = max(maximum, r2[i]);
  }
  int lo = 0, hi = maximum;
  int mid = 0;
  //   if (check(r1, r2, 0))
  //     cout << '0' << endl;
  //   else {
  //     while (lo < hi) {
  //       mid = lo + (hi - lo) / 2;
  //       cerr << hi << ' ' << mid << ' ' << lo << endl;

  //       if (check(r1, r2, mid))
  //         lo = mid;
  //       else
  //         hi = mid;
  //     }
  //   }
  check(r1, r2, 2);
  cerr << hi << ' ' << mid << ' ' << lo << endl;

  return 0;
}