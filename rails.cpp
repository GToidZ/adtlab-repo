#include <iostream>
#include <stack>

using namespace std;

int main() {
  int N, input;
  while (cin >> N && N) {
    while (cin >> input && input) {
      bool flag = true;
      stack<int> fromA, station;
      for (int i = N; i > 0; i--) {
        fromA.emplace(i);  // Make a stack in reverse.
      }
      for (int i = 0; i < N; i++) {
        if (i) cin >> input;
        if (!station.empty() && station.top() == input) {
          station.pop();
        } else {
          while (!fromA.empty() && fromA.top() != input) { // Transfer from A to station
            station.emplace(fromA.top());
            fromA.pop();
          }
          if (fromA.empty()) flag = false;
          else fromA.pop();
        }
      }
      if (flag) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    cout << endl;
  }
}
