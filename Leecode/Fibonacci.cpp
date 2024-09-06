#include <bits/stdc++.h>
using namespace std;
int fib(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    n--;
  return (fib(n) + fib(--n));
}

int main() {
  int n;
  cin >> n;
  cout << fib(n);
  return 0;
}