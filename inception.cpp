#include <iostream>
#include <string.h>
using namespace std;

struct Node {
  char name[20];
  Node *next;

  Node(Node *next=nullptr):
    next(next) {}
};

Node *top = nullptr;

int main() {
  char cmd[10];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cmd;
    if (cmd[0] == 'S') {
      // <name> goes to sleep, add to stack.
      char name[20];
      cin >> name;
      Node *person = new Node();
      strcpy(person->name, name);
      if (top != nullptr) {
        person->next = top;
      } 
      top = person;
    } else if (cmd[0] == 'K') {
      // Kick the top most person out the stack.
      if (top != nullptr) {
        Node *next = top->next;
        delete top;
        top = next;
      }
    } else if (cmd[0] == 'T') {
      // See what person is on the top of stack.
      if (top != nullptr) {
        cout << top->name << endl;
      } else {
        cout << "Not in a dream" << endl;
      }
    }
  }
}
