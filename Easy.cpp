#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Time complexity: O(n) where n is the number or nodes
Space complexity: O(h) where h is the height of the tree
*/

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(vector<int>& nums, int low, int high){
  if(low > high) return NULL;

  int mid = low + (high - low)/2;
  TreeNode* node = new TreeNode(nums[mid]);
  node->left = helper(nums, low, mid-1);
  node->right = helper(nums, mid+1, high);
  return node;
}

TreeNode* sortedArraytoBST(vector<int>& nums){
  if(nums.size()==0) return NULL;
  TreeNode* head = helper(nums, 0, nums.size()-1);
  return head;
}

void preOrder(TreeNode* node){
  if(node == NULL) 
    return;

  cout << node->val << " ";
  preOrder(node->left);
  preOrder(node->right);
}

int main(){
  int n; 
  cout << "Enter the number of nodes: ";
  cin >> n;
  cout << "Enter the nodes: ";
  vector<int> nums(n);
  for(int i=0; i<n; i++){
    cin >> nums[i];
  }
  TreeNode* head = sortedArraytoBST(nums);
  cout << "Preorder Traversal of constructed BST" << endl;
  preOrder(head);
}

