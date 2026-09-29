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
    void bst(TreeNode *root , TreeNode* &pre , TreeNode *&first ,TreeNode * &second){
        if(!root) return ;

        bst(root->left ,pre , first , second) ;

        if(pre!= NULL && pre->val > root->val){
           if(first==NULL){
            first =pre ;
           }

           second = root ;
        }

        pre = root ;

        bst(root->right , pre , first , second);

      
    }
    void recoverTree(TreeNode* root) {
        TreeNode* pre =NULL ;
        TreeNode* first = NULL ;
        TreeNode* second = NULL ;

        bst(root , pre , first ,second);
        swap(first->val ,second->val);
    }
};