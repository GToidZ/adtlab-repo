#include <iostream>
using namespace std;

int main() {
  int n, s, t;
  cin >> n >> s >> t;
  int prices[n];
  int valid_pairs = 0;
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  } // Input all the prices
  for (int i = 0; i < n; i++) {
    if ((i + 1) == n) continue; // Last one don't require finding.
    int current = prices[i];
    int candidates[n-(i+1)];
    copy(prices + i + 1, prices + (i+1) + (n-(i+1)), candidates);
    for (int j = 0; j < sizeof(candidates)/sizeof(candidates[0]); j++) {
      int sum = candidates[j] + current;
      int diff = candidates[j] - current;
      if ((diff <= t) && (sum >= s)) {
        valid_pairs++;
      }
    }
  } // Loop over each price to find good pairs.
  cout << valid_pairs << endl;
}
