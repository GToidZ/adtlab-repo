#include <iostream>
using namespace std;

// Input for starting_index is i + 1.

void stack_hz(int *peaks, int starting_index) {
  // Stacks a horizontal (4-cell) piece.
  int height = 0;
  for (int i = starting_index; i < (starting_index + 4); i++) {
    if (peaks[i] > height) height = peaks[i];
    if ((i + 1) == (starting_index + 4)) {
      peaks[i] = height + 1;
      peaks[i-1] = height + 1;
      peaks[i-2] = height + 1;
      peaks[i-3] = height + 1;
    }
  }
}

void stack_vt(int *peaks, int starting_index) {
  // Stacks a vertical (4-cell) piece.
  peaks[starting_index] += 4;
}

void stack_sq(int *peaks, int starting_index) {
  // Stacks a square (2 by 2) piece.
  int height = 0;
  for (int i = starting_index; i < (starting_index + 2); i++) {
    if (peaks[i] > height) height = peaks[i];
    if ((i + 1) == (starting_index + 2)) {
      peaks[i] = height + 2;
      peaks[i-1] = height + 2;
    }
  }
}

int main() {
  int peaks[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int times;
  cin >> times;
  for (int i = 0; i < times; i++) {
    char type; int starting_index;
    cin >> type >> starting_index;
    if (type == '-') {
      stack_hz(peaks, starting_index - 1);
    } else if (type == 'i') {
      stack_vt(peaks, starting_index - 1);
    } else if (type == 'o') {
      stack_sq(peaks, starting_index - 1);
    }
  }
  int peak = 0;
  for (int i = 0; i < 10; i++) {
    if (peaks[i] > peak) peak = peaks[i];
  }
  cout << peak << endl;
}
