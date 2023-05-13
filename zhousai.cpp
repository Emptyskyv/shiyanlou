#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <numeric>
#include <valarray>
#include <unordered_map>

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
    TreeNode* expandBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left) {
            TreeNode* temp = root->left;
            root->left = new TreeNode(-1, temp, nullptr);
            expandBinaryTree(temp);
        }
        if (root->right) {
            TreeNode* temp = root->right;
            root->right = new TreeNode(-1, nullptr, temp);
            expandBinaryTree(temp);
        }

        return root;
    }
};
int main() {
    string s = "0200";
    int temp = stoi(s);
    cout << temp;
    return 0;
}