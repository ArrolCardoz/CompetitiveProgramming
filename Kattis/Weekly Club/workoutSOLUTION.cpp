#include <iostream>
using namespace std;
// studying solution
const int MAXM = 10;

struct times {
  int usage;     // Time Jim or the person uses the machine
  int recovery;  // Recovery time before they can use the machine again
  int total;     // Total cycle time = usage + recovery
  int start;     // For the person: when their first cycle begins
};

times jim[MAXM];     // Jim's usage/recovery times per machine
times others[MAXM];  // Each machine's other user info

int main() {
  int n = 10;

  // Read Jim's usage and recovery per machine
  for (int i = 0; i < n; i++) {
    cin >> jim[i].usage >> jim[i].recovery;
    jim[i].total = jim[i].usage + jim[i].recovery;
  }

  // Read the other person's usage, recovery, and first start time
  for (int i = 0; i < n; i++) {
    cin >> others[i].usage >> others[i].recovery >> others[i].start;
    others[i].total = others[i].usage + others[i].recovery;
  }

  int t = 0;  // Current time

  // Jim repeats all 10 machines 3 times
  for (int reps = 1; reps <= 3; reps++) {
    for (int m = 0; m < n; m++) {
      // Check if person is using the machine when Jim arrives
      if (t >= others[m].start &&
          (t - others[m].start) % others[m].total <= others[m].usage) {
        // Jim arrives during usage or at same moment -> he waits
        t += others[m].usage - (t - others[m].start) % others[m].total;
      }

      // Align the other person’s cycle anchor to most recent start time
      if (t >= others[m].start) {
        others[m].start = t - (t - others[m].start) % others[m].total;
      }

      // Check if Jim’s usage will conflict with the next usage cycle
      if (others[m].start + others[m].total < t + jim[m].usage) {
        // Jim blocks the next cycle, so delay it
        others[m].start = t + jim[m].usage;
      } else if (t < others[m].start && t + jim[m].usage > others[m].start) {
        // Jim would begin before and block a person scheduled soon
        others[m].start = t + jim[m].usage;
      }

      // Jim finishes usage + recovery
      t += jim[m].total;
    }
  }

  // Don't count Jim's final recovery on last machine
  cout << t - jim[n - 1].recovery << endl;

  return 0;
}
