#include <iostream>

using namespace std;

int q[210];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> q[i];
    }
    int id = 0, ans = 0;
    while (q[m]) {
      int max = -999999;
      for (int i = 0; i < n; i++) {
        if (q[i] > max) max = q[i];
      }
      if (q[id] == max) {
        q[id] = 0;
        ans++;
      }
      id = (id + 1) % n;
    }
    cout << ans << endl;
  }
}
