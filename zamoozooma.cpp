#include <iostream>
using namespace std;

struct Ball {
  int number;
  Ball *front;
  Ball *rear;
  Ball(int n, Ball *front=nullptr, Ball *rear=nullptr)
    : number(n), front(front), rear(rear) {}
};

Ball *first = nullptr;
Ball *last = nullptr;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int d, a;
    cin >> d >> a;
    if (d == 0) {
      Ball *ball = new Ball(a, nullptr, first);
      first = ball;
      if (last == nullptr) last = ball;

      Ball *cursor = first;
      while (cursor->rear != nullptr) {
        if (cursor->rear->number == a) {
          // Traverse back the chain, deleting from the start.
          while (first != cursor->rear->rear) {
            Ball *next = first->rear;
            delete first;
            first = next;
          }
          break;
        }
        cursor = cursor->rear;
      }
    } else if (d == 1) {
      Ball *ball = new Ball(a, last, nullptr);
      last = ball;
      if (first == nullptr) first = ball;

      Ball *cursor = last;
      while (cursor->front != nullptr) {
        if (cursor->front->number == a) {
          // Traverse back the chain, deleting from the start.
          while (last != cursor->front->front) {
            Ball *next = last->front;
            delete last;
            last = next;
          }
          break;
        }
        cursor = cursor->front;
      }
    }
  }
  int count = 0;
  Ball *cursor = first;
  while (cursor != nullptr) {
    cursor = cursor->rear;
    count++;
  }
  cout << count << endl;
}
