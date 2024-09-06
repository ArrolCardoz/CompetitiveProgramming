#include <bits/stdc++.h>
using namespace std;

void solution() {}

int main() {
  map<long long, int> map;

  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;

    for (long long j = a; j <= b; j++) map[j]++;
  }

  for (auto &it : map) cout << it.first << " " << it.second << endl;

  return 0;
}