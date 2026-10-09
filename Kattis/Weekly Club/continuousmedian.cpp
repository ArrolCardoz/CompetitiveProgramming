
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int64_t, null_type, less_equal<int64_t>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds;  // find_by_order, order_of_key

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solution() {
  int n;
  cin >> n;
  pbds A;
  int input;
  int64_t total = 0;
  for (int i = 1; i <= n; i++) {
    cin >> input;
    A.insert(input);
    if ((i % 2)) {
      total += *A.find_by_order((i / 2));

    } else {
      int64_t a = *A.find_by_order((i / 2) - 1);
      int64_t b = *A.find_by_order(i / 2);
      total += a + (b - a) / 2;
    }
  }
  cout << total << endl;
}

int main() {
  fastIO();
  int n;
  cin >> n;
  while (n--) {
    solution();
  }
  return 0;
}