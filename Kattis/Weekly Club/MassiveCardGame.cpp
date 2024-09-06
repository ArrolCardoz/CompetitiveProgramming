#include <bits/stdc++.h>
using namespace std;
void solution() {}
int main() {
  map<long long, long long> array;

  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    array[i]++;
  }
  long long a, b, m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    cout << accumulate(find(array.begin(), array.end(), a),
                       find(array.begin(), array.end(), a), 0);
  }
  return 0;
}