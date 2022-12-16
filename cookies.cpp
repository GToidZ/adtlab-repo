#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Row;

void eat(Row *cookies, int index) {
  if (cookies->size() < index+1) return;
  cookies->erase(cookies->begin() + index - 1);
}

void insert(Row *cookies, int index, int n) {
  if (cookies->size() < index+1) {
    cookies->push_back(n);
    return;
  }
  cookies->insert(cookies->begin() + index, n);
}

int main() {
  int ops;
  Row cookies;
  cin >> ops;
  for (int i = 0; i < ops; ++i) {
    int op, k;
    cin >> op >> k;
    if (op == 1) {
      int n;
      cin >> n;
      insert(&cookies, k, n);
    }
    if (op == 2) {
      eat(&cookies, k);
    }
  }
  for (auto c = cookies.begin(); c != cookies.end(); c++) {
    cout << *c << endl;
  }
}
