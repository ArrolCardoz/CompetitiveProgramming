/*
Note: I did solve the question in both ways mentioned in lab 1st with pbds and
below it with priority queue.
I added the priority queue because the solution for pbds is straight foward and
felt like cheating
References:-
Textbook -> 2.3.4
https://codeforces.com/blog/entry/11080
https://www.youtube.com/watch?v=IWyIwLFucU4

Solution:-
The solution for psbd is straight foward,
few comments about the setup - I used int although not necessary for storing
the set each int is up to 10^9, but I will need int64_t for adding up the total.
I used less_equal<int> comparator because it is not mentioned that all the
numbers are distinct or not, so I'm using a multiset instead of a set.
That is it for the setup only 2 choices and the remaining is solution is
straight foward because I can access any index with find_by_order() in pbds.
I used the trick to not overflow when taking the average when the size is even.

Priority solution:-
The solution function looks similar with one more step of balancing the min and
max priority queues
*/
#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>  //psbd
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
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

/*
using priority queue
-------------------------
#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solution() {
//initialize
  int n;
  priority_queue<int> maxQ;
  priority_queue<int, vector<int>, greater<int>> minQ;
  int64_t total = 0;
  cin >> n;

  //solution
  while (n--) {
    int curr;
    cin >> curr;
    if (minQ.size() > 0) {
      if (minQ.top() < curr) {
        minQ.push(curr);
      } else
        maxQ.push(curr);
    } else
      minQ.push(curr);

    //balance the queues
    if (minQ.size() - 2 == maxQ.size()) {
      int temp = minQ.top();
      minQ.pop();
      maxQ.push(temp);
    } else if (minQ.size() == maxQ.size() - 2) {
      int temp = maxQ.top();
      maxQ.pop();
      minQ.push(temp);
    } else if (minQ.size() < maxQ.size()) {
      int temp = maxQ.top();
      maxQ.pop();
      minQ.push(temp);
    }
  //get the avarage or median depending if its odd or even
    if ((maxQ.size() + minQ.size()) % 2) {
      total += minQ.top();
    } else {
      int64_t temp = maxQ.top();
      temp = temp + (minQ.top() - temp) / 2;
      total += temp;
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
*/