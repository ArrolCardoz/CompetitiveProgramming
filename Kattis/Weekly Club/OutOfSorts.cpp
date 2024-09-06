#include <bits/stdc++.h>
using namespace std;
// map<int, int> sequence;

long long begin, end;

int solution(long long n, vector<long long> sequence) {
  long long loop = sequence.size();

  long long counter = 0;
  bool isTrue = false;

  for (long long i = 0; i < sequence.size(); i++) {
    long long low = 0;
    long long high = sequence.size() - 1;
    long long loop = sequence.size() - 1;
    // cout << counter << endl;

    // cout << "============================" << sequence.size() << " " << i
    // << endl;
    while (!(low > high)) {
      auto mid = (low + high) / 2;

      if (sequence[mid] == sequence[i]) {
        counter++;
        isTrue = true;

      } else if (sequence[i] > sequence[mid])  // 4>8
        low = mid + 1;
      else
        high = mid - 1;
      // cout << sequence[i] << ">" << sequence[mid] << endl;
      // cout << low << " " << high << " " << mid << endl;
      if (isTrue) break;
    }

    isTrue = false;
  }
  //  cout << counter << endl << endl;
  return counter;
}

void formula(long long n, long long m, long long a, long long c, long long x,
             vector<long long>& sequence) {
  long long prev = 0;
  long long ans;

  for (long long i = 0; i < n; i++) {
    // cout << a << " " << prev << " " << c << " " << m << endl;
    if (i == 0) {
      ans = ((a * x) + c) % m;

    } else
      ans = ((a * (prev)) + c) % m;

    //   cout << ans << " ";
    prev = ans;
    sequence.push_back(prev);
  }
}
int main() {
  long long n, m, a, c, x;
  vector<long long> sequence;
  cin >> n >> m >> a >> c >> x;
  formula(n, m, a, c, x, sequence);

  cout << endl << solution(n, sequence);

  return 0;
}