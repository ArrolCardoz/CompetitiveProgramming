#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

bool check(const vvi& A, const int& n) {
  int ctr = 0;
  int prev = -1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < (int)A[i].size(); j++) {
      if (A[i][j] <= n) continue;  // skip

      if (ctr) {  // check odd or even
        if (prev != A[i][j]) return false;
        prev = -1;
      } else {
        prev = A[i][j];
      }
      ctr = 1 - ctr;  // increment ctr
    }
    if (prev != -1) return false;
  }
  return true;
}

void solution(const vvi& A, const vi& ost, const int& n) {
  int hi = n - 1;
  int lo = 0;
  while (hi > lo) {
    int mid = lo + (hi - lo) / 2;
    if (check(A, ost[mid * 2])) {
      hi = mid;

    } else {
      lo = mid + 1;
    }
  }
  cout << ost[hi * 2] << endl;
}

int main() {
  fastIO();
  int n;
  string str;
  vi ost;
  vvi A(2);
  cin >> n;
  A[0].reserve(n * 2);
  A[1].reserve(n * 2);
  cin.ignore(100, '\n');

  for (int i = 0; i < 2; i++) {
    getline(cin, str);
    stringstream ss(str);
    int num;
    while (ss >> num) {
      ost.push_back(num);
      A[i].push_back(num);
    }
  }
  sort(ost.begin(), ost.end());
  if (check(A, 0)) {
    cout << 0 << endl;
  } else {
    solution(A, ost, n);
  }
  return 0;
}