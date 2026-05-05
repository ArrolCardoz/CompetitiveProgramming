#include <bits/stdc++.h>
using namespace std;

const int maxMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {
  int year, month, date, hour, min;
  bool state;
  // arrive=1,depart=0
};

ostream& operator<<(ostream& os, const date& d) {
  os << d.year << "-" << d.month << "-" << d.date << " " << d.hour << ":"
     << d.min;
  return os;
}

date operator+(date a, int b) {
  a.min += b;
  while (a.min >= 60) {
    a.min -= 60;
    a.hour++;
  }

  while (a.hour >= 24) {
    a.hour -= 24;
    a.date++;

    int limit = maxMonth[a.month - 1];
    if (a.month == 2 && a.year == 2016) {
      limit = 29;
    }

    if (a.date > limit) {
      a.date = 1;
      a.month++;

      if (a.month > 12) {
        a.month = 1;
        a.year++;
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
            // state
            if (!a.state && b.state) return true;
            return false;
          }
        }
      }
    }
  }
}

void solution() {
  int n, cleaningTime;
  vector<date> bookings;

  cin >> n >> cleaningTime;
  // cerr << n * 2 << endl;
  bookings.reserve(n * 2);
  // cerr << n * 2 << endl;

  if (!n) return;
  while (n--) {
    char temp[25];

    date arrive, depart;
    arrive.state = 1;
    depart.state = 0;
    //  arrivedate
    scanf("%s %d-%d-%d %d:%d", temp, &arrive.year, &arrive.month, &arrive.date,
          &arrive.hour, &arrive.min);

    //  depart

    scanf("%d-%d-%d %d:%d", &depart.year, &depart.month, &depart.date,
          &depart.hour, &depart.min);

    depart = depart + cleaningTime;

    bookings.push_back(arrive);
    bookings.push_back(depart);
  }
  sort(begin(bookings), end(bookings), sortDate);
  int ans = 0, MAXans = 0;
  for (auto& it : bookings) {
    if (it.state) {
      ans++;
      MAXans = max(ans, MAXans);
    } else
      ans--;
  }
  cout << MAXans << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    solution();
  }
  return 0;
}