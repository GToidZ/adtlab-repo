#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int GREEN_MOD = 1;
int BLACK_MOD = -1;

struct Box {
  ll green;
  ll black;

  Box(ll g, ll b):
    green(g), black(b) {}
};

vector<Box> boxes;
vector<ll> results;

ll sum_of_all_boxes() {
  ll sum = 0;
  for (int i = 0; i < boxes.size(); i++) {
    sum += (boxes[i].green * GREEN_MOD) + (boxes[i].black * BLACK_MOD);
  }
  return sum;
}

void k1(int N) {
  for (int i = 0; i < N; i++) {
    // store removed index and element as temp
    int indexTmp = i;
    Box boxTmp = boxes[indexTmp];
    boxes.erase(boxes.begin()+indexTmp);
    // sum and store
    ll sum = 0;
    for (int j = 0; j < boxes.size(); j++) {
      sum += (boxes[j].green * GREEN_MOD) + (boxes[j].black * BLACK_MOD);
    }
    results.push_back(sum);
    // restore element at index.
    boxes.insert(boxes.begin()+indexTmp, boxTmp);
  }
}

void k2(int N) {
  for (int i = 0; i < N - 1; i++) {
    int indexTmp = i;
    Box boxTmp = boxes[indexTmp];
    boxes.erase(boxes.begin()+indexTmp);
    for (int j = i+1; j < boxes.size(); j++) {
      int innerIndexTmp = j;
      Box innerBoxTmp = boxes[innerIndexTmp];
      boxes.erase(boxes.begin()+innerIndexTmp);
      ll sum = 0;
      for (int k = 0; k < boxes.size(); k++) {
        sum += (boxes[k].green * GREEN_MOD) + (boxes[k].black * BLACK_MOD);
      }
      results.push_back(sum);
      boxes.insert(boxes.begin()+innerIndexTmp, innerBoxTmp);
    }
    boxes.insert(boxes.begin()+indexTmp, boxTmp);
  }
}

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    ll green, black;
    cin >> green >> black;
    boxes.push_back(*(new Box(green, black)));
  }
  results.push_back(sum_of_all_boxes());
  if (K >= 1) {
    k1(N);
  }
  if (K >= 2) {
    k2(N);
  }
  cout << *std::max_element(results.begin(), results.end()) << endl;
}
