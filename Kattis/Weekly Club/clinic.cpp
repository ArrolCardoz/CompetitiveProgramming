#include <bits/stdc++.h>
using namespace std;

typedef pair<int64_t, string> pis;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

struct Cmp {
  bool operator()(const pis& a, const pis& b) const {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
  }
};

void getPatient(priority_queue<pis, vector<pis>, Cmp>& pq,
                unordered_set<string>& callIn) {
  if (pq.empty()) {
    cout << "doctor takes a break" << endl;
    return;
  }
  pis curr = pq.top();
  pq.pop();
  auto it = callIn.find(curr.second);
  if (it != callIn.end()) {
    callIn.erase(it);
    getPatient(pq, callIn);
    return;
  }
  cout << curr.second << endl;
}

int main() {
  fastIO();
  int n, k;
  priority_queue<pis, vector<pis>, Cmp> pq;
  unordered_set<string> callIn;

  cin >> n >> k;
  while (n--) {
    int caseNum;
    cin >> caseNum;
    switch (caseNum) {
      case 1: {
        int64_t time, s;
        string name;
        cin >> time >> name >> s;
        pq.push({s - k * time, name});
        break;
      }
      case 2: {
        int64_t time;
        cin >> time;
        getPatient(pq, callIn);
        break;
      }
      case 3: {
        int64_t time;
        string name;
        cin >> time >> name;
        callIn.insert(name);
      }
    }
  }
  return 0;
}