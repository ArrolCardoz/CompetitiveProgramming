#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> jim(10);
  int usage, recovery;

  // Jim's schedule
  for (int i = 0; i < 10; i++) {
    cin >> usage >> recovery;
    jim[i] = usage + recovery;
  }

  // Other people: usage, recovery, start time
  vector<tuple<int, int, int>> usageRecTime(10);
  for (int i = 0; i < 10; i++) {
    int t;
    cin >> usage >> recovery >> t;
    usageRecTime[i] = make_tuple(usage, recovery, t);
  }

  int time = 0;
  for (int round = 0; round < 3; round++) {
    for (int i = 0; i < 10; i++) {
      if (round == 0 && i == 0) {
        time += jim[i];
        continue;
      }

      int ou = get<0>(usageRecTime[i]);
      int orr = get<1>(usageRecTime[i]);
      int start = get<2>(usageRecTime[i]);
      int cycle = ou + orr;

      if (start > time) {
        time += jim[i];
        continue;
      }

      int offset = time - start;
      int pos = offset % cycle;

      if (pos >= ou) {
        // Person is in recovery — Jim can start
        time += jim[i];
      } else {
        // Person is using the machine — Jim waits
        time += (ou - pos);
        time += jim[i];
      }
    }
  }

  cout << time << endl;
  return 0;
}
