#include <bits/stdc++.h>
using namespace std;

const vector<int> daysInMonth = {0,  31, -1, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int isLeap(int year) {
  if (year % 400 == 0) return 29;
  if (year % 100 == 0) return 28;
  if (year % 4 == 0) return 29;
  return 28;
}

bool isValid(int date, int month, int year) {
  if (year < 2000 || month > 12 || date == 0 || month == 0) return false;
  if (daysInMonth[month] != -1) {
    return date <= daysInMonth[month];
  } else {
    return date <= isLeap(year);
  }
}

void toDate(string const str, int& date, int& month, int& year) {
  date = (str[0] - '0') * 10;
  date += (str[1] - '0');
  month = (str[2] - '0') * 10;
  month += (str[3] - '0');
  year = (str[4] - '0') * 1000;
  year += (str[5] - '0') * 100;
  year += (str[6] - '0') * 10;
  year += (str[7] - '0');
}

void solution() {
  int date, month, year;
  string str, temp1, temp2;
  cin >> str >> temp1 >> temp2;
  str += temp1;
  str += temp2;
  sort(str.begin(), str.end());
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;

  do {
    toDate(str, date, month, year);
    if (isValid(date, month, year)) {
      pq.push({year, month, date});
    }
  } while (next_permutation(str.begin(), str.end()));
  if (pq.empty())
    cout << 0 << endl;
  else
    cout << pq.size() << ' ' << setfill('0') << setw(2) << get<2>(pq.top())
         << ' ' << setfill('0') << setw(2) << get<1>(pq.top()) << ' '
         << get<0>(pq.top()) << endl;
}
int main() {
  fastIO();
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}