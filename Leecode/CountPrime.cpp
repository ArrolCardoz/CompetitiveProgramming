// 204
// sieve of eratosthenes algo
#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
  vector<int> arr(n + 1, true);
  int count = 0;
  for (int i = 2; i < n; i++) {
    if (arr[i]) {
      count++;

      for (int j = i * 2; j < n; j += i) {
        arr[j] = false;
      }
    }
  }
  //   cout << count;
  return count;
}

int main() {
  int n = 5;
  cout << countPrimes(n) << endl;
  return 0;
}