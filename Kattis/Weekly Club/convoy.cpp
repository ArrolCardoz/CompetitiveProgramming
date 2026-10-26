/*
Idea: Greedy idea for this problem is always use the minimum time taken by a
person to transport the destination 'B'

Implementation: To get the minimum time we have to either sort the given list or
use a priority queue which is faster.
That is what I use.

Priority Queue: The priority queue I have is a tuple of three 64 bit integers.
Tuple -> 1. Time taken to transport (t)
         2. The index of the value 't' from the input in vector 'num'
         3. The current location. 1 is location 'B' which is the destination and
                                  0 is the location 'A' which is the start
                                  location

Vectors:-
'Num': I store the input in this vector and sort it. Its the time taken
't' Vector 'Times': This is the multipler of 't' which stores the

Idea:
Sort the input array then,
We push minimum of k or n people into the priority queue. Which is the number of
people that can use the car.

We do not care if there is a tie in time 't' the only thing we need to keep
track of is the current position of the top person in the priority queue (PQ)
and the total amout of people in the start destination.

If the current person is in destination 'A' then it can take 5 people to
destination 'B' else it can take 4 people.
When putting the person back into the queue we add two in the multiplyer vector
(times) and add (t * multiplier) into the priority queue.

We repeat the about step till total is equal to 0.

 */
#include <bits/stdc++.h>
using namespace std;
#define tlll tuple<int64_t, int64_t, int64_t>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n, k;
  priority_queue<tlll, vector<tlll>, greater<tlll>> pq;
  cin >> n >> k;
  vector<int64_t> num(n);
  vector<int64_t> times(n, 0);

  // input
  for (auto& it : num) cin >> it;

  sort(num.begin(), num.end());

  // fill PQ
  for (int64_t i = 0; i < min(k, n); i++) {
    pq.push({num[i], i, 0LL});
    times[i]++;
  }

  int64_t ans = 0;
  int total = n;

  // solution
  while (total > 0) {
    auto [t, idx, pos] = pq.top();
    pq.pop();

    if (pos) {
      total -= min(total, 4);
    } else {
      total -= min(total, 5);
      k--;
    }
    ans = t;
    times[idx] += 2;
    pq.push({num[idx] * (times[idx]), idx, 1});
  }
  cout << ans << endl;

  return 0;
}