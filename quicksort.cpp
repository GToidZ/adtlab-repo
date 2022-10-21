#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int x[100010];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x+n);
 // for (int i = 0; i < n; i++) {
 //   cout << x[i] << endl;
 // }
  int N = floor(n/k);
  for (int i = 1; i <= N; i++) {
    cout << x[(i*k)-1] << endl;
  }
}
