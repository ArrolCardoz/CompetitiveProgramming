#include <bits/stdc++.h>
using namespace std;

const int maxMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {
  int year, month, date, hour, min;
  bool state;
  // arrive=1,depart=0
};

date operator+(date a, int b) {
  a.date = (a.date + (b % 60)) % 60;

  if (a.min + b >= 60) {
    a.hour = (a.hour + (b / 60)) % 24;
    if (a.hour + (b / 60) >= 24) {
      a.date++;
      if (a.date > maxMonth[a.month - 1]) {
        // leap year
        if (a.month != 2 && a.year != 2016) {
          a.date = 1;
          a.month++;
          if (a.month > 12) {
            a.month = 1;
            a.year++;
          }
        }
      }
    }
  }
  return a;
}

bool sortDate(date a, date b) {
  // year
  if (a.year < b.year)
    return true;
  else if (b.year < a.year)
    return false;
  else {
    // month
    if (a.month < b.month)
      return true;
    else if (b.month < a.month)
      return false;
    else {
      // date
      if (a.date < b.date)
        return true;
      else if (b.date < a.date)
        return false;
      else {
        // hour
        if (a.hour < b.hour)
          return true;
        else if (b.hour < a.hour)
          return false;
        else {
          // min
          if (a.min < b.min)
            return true;
          else if (b.min < a.min)
            return false;
          else {
            return true;
          }
        }
      }
    }
  }
}

bool solution() {
  int n, cleaningTime;
  vector<date> bookings;

  cin >> n >> cleaningTime;
  // cerr << n * 2 << endl;
  bookings.reserve(n * 2);
  // cerr << n * 2 << endl;

  if (!n) return false;
  while (n--) {
    string temp;
    char str;
    int num;
    date arrive, depart;
    arrive.state = 1;
    depart.state = 0;
    cin >> temp;
    // cerr << temp << ' ';
    //  arrivedate
    cin >> num;
    cin >> str;
    arrive.year = num;
    // cerr << num << ' ';
    cin >> num;
    cin >> str;
    arrive.month = num;
    // cerr << num << ' ';
    cin >> num;
    arrive.date = num;
    // cerr << num << ' ';
    cin >> num;
    cin >> str;
    arrive.hour = num;
    // cerr << num << ' ';
    cin >> num;
    arrive.min = num;
    // cerr << num << ' ';
    //  depart
    cin >> num;
    cin >> str;
    depart.year = num;
    cin >> num;
    cin >> str;
    depart.month = num;
    cin >> num;
    depart.date = num;
    cin >> num;
    cin >> str;
    depart.hour = num;
    cin >> num;
    depart.min = num;
    depart = depart + cleaningTime;
    bookings.push_back(arrive);
    bookings.push_back(depart);
  }
  sort(begin(bookings), end(bookings), sortDate);
  int ans = 0, MAXans = -1;
  for (auto& it : bookings) {
    if (it.state) {
      ans++;
      MAXans = max(ans, MAXans);
    } else
      ans--;
  }
  cout << MAXans << endl;
  return true;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    solution();
  }
  return 0;
}