#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int T[N][N];
  int rows[N], cols[N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> T[i][j];
    }
  }

  // Find row
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      sum = sum + T[i][j];
    }
    rows[i] = sum;
  }

  // Find col
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      sum = sum + T[j][i];
    }
    cols[i] = sum;
  }

  // Check for each row for different member.
  int first, second, latest, culpritR;
  for (int r = 0; r < N; r++) {
    if (r == 0) {
      first = rows[r];
    } else if (r == 1) {
      second = rows[r];
    } else if (r > 1) {
      if (first == second) {
        if (rows[r] != first) {
          culpritR = r;
          break;
        }
      }
    }
    latest = r;
  }

  if (first != second) {
    if (rows[latest] == first) {
      culpritR = 1;
    } else {
      culpritR = 0;
    }
  }

  // Check for each col for different member.
  int culpritC;
  for (int c = 0; c < N; c++) {
    if (c == 0) {
      first = cols[c];
    } else if (c == 1) {
      second = cols[c];
    } else if (c > 1) {
      if (first == second) {
        if (cols[c] != first) {
          culpritC = c;
          break;
        }
      }
    }
    latest = c;
  }

  if (first != second) {
    if (cols[latest] == first) {
      culpritC = 1;
    } else {
      culpritC = 0;
    }
  }
  
  cout << T[culpritR][culpritC] << endl;

}
