/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int height(TreeNode* root){
        if(!root->left && !root->right) return 1;

        int Left = 0 , Right = 0;
        if(root->left) Left = height(root->left);
        if(root->right) Right = height(root->right);
    
        return (Left > 0 && Right > 0) ? min(Left,Right) + 1 : max(Left,Right) + 1;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return height(root);
    }
};