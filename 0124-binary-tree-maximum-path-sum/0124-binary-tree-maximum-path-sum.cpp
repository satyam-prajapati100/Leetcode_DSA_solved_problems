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
    int find(TreeNode * root ,int &main){
        if(!root){
            return 0;
        }

        int leftsum = max(0 , find(root->left  ,main));
        int rightsum = max(0 ,find(root->right , main));

        main = max(main , leftsum + rightsum + root->val);

        return root->val + max(leftsum , rightsum);

    }
    
    int maxPathSum(TreeNode* root) {
        int main = INT_MIN ; 

        find(root , main);

        return main;
    }
};