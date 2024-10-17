
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
  int maxProfit = 0;
  int minPrice = prices[0];
  for (int i = 1; i < prices.size(); i++) {
    // cout << maxProfit << endl;
    if (maxProfit < (prices[i] - minPrice)) maxProfit = prices[i] - minPrice;
    if (minPrice > prices[i]) minPrice = prices[i];
  }

  return maxProfit;
}

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << maxProfit(prices);
  return 0;
}