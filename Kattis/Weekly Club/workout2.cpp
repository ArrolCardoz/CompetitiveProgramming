#include <bits/stdc++.h>
using namespace std;
// attempt 2
// failed again X(
struct Jim {
  int usage;
  int recovery;
};

struct People {
  int time;
  int usage;
  int recovery;
};
int main() {
  Jim jim[10];
  int use, rec;
  for (int i = 0; i < 10; i++) {
    cin >> use >> rec;
    jim[i].recovery = rec;
    jim[i].usage = use;
  }
  People people[10];
  int time;
  for (int i = 0; i < 10; i++) {
    cin >> use >> rec >> time;
    people[i].recovery = rec;
    people[i].usage = use;
    people[i].time = time;
  }
  time = jim[0].usage;
  time += jim[0].recovery;
  if (people[0].time < jim[0].usage) people[0].time = jim[0].usage;

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 10; i++) {
      if (j == 0 && i == 0) continue;
      // check if machine is free
      int cycle = people[i].recovery + people[i].usage;
      //   cout << "CYCLE" << cycle << endl;
      if (people[i].time < time &&
          ((time - people[i].time) % cycle) < people[i].usage) {
        // cout << time << '+' << people[i].time << '%' << cycle << endl;
        if (jim[i].usage > (people[i].time + people[i].recovery) -
                               (time - people[i].time) % cycle) {
          time += jim[i].usage;
          people[i].time = time;
          time += jim[i].recovery;
        } else {
          time += jim[i].usage;
          time += jim[i].recovery;
        }
      } else {  // if machine is not free
        // cout << j << ' ' << i << endl;
        // cout << time << '+' << people[i].time << '%' << cycle << endl;
        // cout << (time + people[i].time) % cycle << " >= " << people[i].usage
        //      << endl;
        // cout << people[i].usage - (time + people[i].time) % cycle << endl;
        time += people[i].usage - (time - people[i].time) % cycle;
        if (jim[i].usage > (people[i].time + people[i].recovery) -
                               (time - people[i].time) % cycle) {
          time += jim[i].usage;
          people[i].time = time;
          time += jim[i].recovery;
        } else {
          time += jim[i].usage;
          time += jim[i].recovery;
        }
      }
      //   cout << time << endl;
    }
  }
  time -= jim[9].recovery;
  cout << time << endl;
  return 0;
}