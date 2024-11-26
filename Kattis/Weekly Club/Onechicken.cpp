#include <bits/stdc++.h>
using namespace std;

int main() {
  int people, chicken;

  cin >> people >> chicken;
  int ans = people - chicken;
  if (ans < 0) {
    if (abs(ans) == 1)
      cout << "Dr. Chaz will have " << abs(ans)
           << " piece of chicken left over!";
    else
      cout << "Dr. Chaz will have " << abs(ans)
           << " pieces of chicken left over!";
  } else {
    if (abs(ans) == 1)
      cout << "Dr. Chaz needs " << ans << " more piece of chicken!";
    else
      cout << "Dr. Chaz needs " << ans << " more pieces of chicken!";
  }
  return 0;
}