#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxlength = 0;

    int reverse(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = reverse(root->left);
        int right = reverse(root->right);
        int left1 = 0;
        int right1 = 0;
        if (root->left && root->left->val == root->val) {
            left1 = 1 + left;
        }
        if (root->right && root->right->val == root->val) {
            right1 = 1 + right;
        }
        maxlength = max(maxlength, left1 + right1);

        return max(left1, right1);
    }

    int longestUnivaluePath(TreeNode *root) {
        reverse(root);

        return maxlength;
    }

};
