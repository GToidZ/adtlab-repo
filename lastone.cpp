#include <iostream>
#include <vector>

using namespace std;

vector<int> people;

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    people.push_back(i);
  }
  int cursor = 0, interval = 1;
  int latest;
  while (people.size()) {
    if (K == 1) {
      latest = people[people.size()-1];
      break;
    }
    if (people.size() == 1) { // Final person
      latest = people[0];
      people.erase(people.begin());
    }
    if (interval >= K) { // When interval reaches K.
      interval = 1;
      latest = people[cursor];
      people.erase(people.begin()+cursor);
      if (cursor >= people.size()) { cursor = 0; }
      continue;
    }
    if (cursor == people.size()-1) {
      cursor = 0;
    } else {
      cursor++;
    }
    interval++;
  }
  cout << latest << endl;
}
