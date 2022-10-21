#include <iostream>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0)
    : val(val), left(left), right(right) {}
};

void inorder(TreeNode* r)
{
  if(!r) {
    return;
  }
  inorder(r->left);
  cout << r->val << endl;
  if(r != NULL) inorder(r->right);
}

int main() {
  TreeNode* root = new TreeNode(20);
  TreeNode* five = new TreeNode(5);
  TreeNode* forty = new TreeNode(40);
  TreeNode* threeFive = new TreeNode(35);
  TreeNode* seven = new TreeNode(7);

  root->left = five;
  root->right = forty;
  forty->left = threeFive;
  five->right = seven;

  inorder(root);
}
