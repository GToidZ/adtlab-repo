#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int x[100010];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x+n);
  int diff = INT_MAX;
  for (int i = 0; i < n-1; i++) {
    int d = abs(x[i+1] - x[i]);
    if (d < diff) {
      diff = d;
    }
  }
  cout << diff << endl;
}
