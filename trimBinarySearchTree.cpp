/*
 * Trim a Binary Search Tree
 * Yufang Lin
 *
 * My Solution to leetCode problem called, "Trim a Binary Search Tree":
 * https://leetcode.com/problems/trim-a-binary-search-tree/description/
*/

#include <iostream>		// For cout and cin
#include <string>		// For strings


using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 


class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		// Check if at the end of tree or not
		if (root == NULL) {
			return NULL;
		}

		// Check if root's value is greater than upper bound
		if (root->val > R) {
			// since root's value is greater than the upper bound we want to skip to 
			// the root's left child, since it's value will be less than the root's value 
			// and hopefully less than the upper bound
			return trimBST(root->left, L, R);
		}

		// Check if root's value is less than lower bound
		if (root->val < L) {
			// since root's value is less than the lower bound we want to skip to 
			// the root's right child, since it's value will be greater than the root's value 
			// and hopefully greater than the lower bound
			return trimBST(root->right, L, R);
		}

		// Found a root that fits in range
		// Set the root's left child
		root->left = trimBST(root->left, L, R);

		// set the root's right child
		root->right = trimBST(root->right, L, R);

		// return the new root
		return root;
	}

};

int main() {

	// Create an instance of the Solution class
	Solution *sol = new Solution();

	// -- Tree 1 example -- 
	TreeNode* tree1Root = new TreeNode(1);
	TreeNode* tree1Left = new TreeNode(0);
	TreeNode* tree1Right = new TreeNode(2);
		// set root's children
	tree1Root->left = tree1Left;
	tree1Root->right = tree1Right;


	// -- Tree 2 example -- 
	TreeNode* tree2Root = new TreeNode(3);
	TreeNode* tree2Left = new TreeNode(0);
	TreeNode* tree2Right = new TreeNode(4);
	TreeNode* tree2LeftRight = new TreeNode(2);
	TreeNode* tree2LeftRightLeft = new TreeNode(1);
		// set root's children
	tree2Root->left = tree2Left;
	tree2Root->right = tree2Right;
		// set root's left's children
	tree2Left->right = tree2LeftRight;
		// set root's left's right's children
	tree2LeftRight->left = tree2LeftRightLeft;


	// Trim Tree 1 example
	TreeNode* example1 = sol->trimBST(tree1Root, 1, 2);
	// Trim Tree 2 example
	TreeNode* example2 = sol->trimBST(tree2Root, 1, 3);

	return 0;
}