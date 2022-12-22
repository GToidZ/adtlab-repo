#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, dist, rate;
  while (cin >> n >> dist >> rate && n && dist && rate) {
    vector<int> morning(n, 0);
    vector<int> evening(n, 0);
    // Morning
    for(int i = 0; i < morning.size(); i++) {
      cin >> morning[i];
    }
    stable_sort(morning.begin(), morning.end());
    // Evening
    for(int i = 0; i < evening.size(); i++) {
      cin >> evening[i];
    }
    stable_sort(evening.begin(), evening.end(), greater<int>()); // Sort desceding.
    int ot = 0;
    for (int i = 0; i < n; i++) {
      int hr = morning[i] + evening[i];
      if (hr>dist) {
        ot += hr-dist;
      }
    }
    cout << ot*rate << endl;
  }
}
