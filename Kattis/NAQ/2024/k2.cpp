#include <bits/stdc++.h>
using namespace std;

int check(int n) {
  // Calculate score based on the absolute difference
  if (n < 0) n *= -1;
  if (n < 15)
    return 7;
  else if (n < 23)
    return 6;
  else if (n < 43)
    return 4;
  else if (n < 102)
    return 2;
  return 0;
}

void solution() {
  int n, m;
  cin >> n >> m;
  vector<long long> expected(n);
  vector<long long> actual(m);

  for (int i = 0; i < n; i++) {
    cin >> expected[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> actual[i];
  }

  int ans = 0;

  // Use two pointers to match elements from both arrays
  int exptCounter = 0, actuCounter = 0;

  while (exptCounter < n && actuCounter < m) {
    long long sum = expected[exptCounter] - actual[actuCounter];
    int tempAns = check(sum);

    if (tempAns > 0) {
      ans += tempAns;  // Add score if a match is found
      exptCounter++;   // Move to next expected
      actuCounter++;   // Move to next actual
    } else {
      // If the score is zero, we need to adjust our pointers
      if (sum < 0) {
        actuCounter++;  // Move to next actual
      } else {
        exptCounter++;  // Move to next expected
      }
    }
  }

  cout << ans << endl;  // Output the final score
}

int main() {
  solution();
  return 0;
}
