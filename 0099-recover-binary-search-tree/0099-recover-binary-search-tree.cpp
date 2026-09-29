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
    void bst(TreeNode* root , TreeNode* &pre ,TreeNode* &first , TreeNode * &second){
        while(root){
            if(!root->left){
                if(pre != NULL && pre->val > root->val){
                    if(first == NULL){
                        first = pre ;
                    }
                    second = root ;

                }
                pre =root ;
                root = root->right ;
                

            }
            else {
                TreeNode * curr = root->left ;

                while(curr->right && curr->right != root){
                    curr = curr->right ;
                }
                if(curr->right == NULL){
                    curr->right = root ;
                    root =root->left ;
                }
                else {
                    curr->right = NULL ;
                    if(pre != NULL && pre->val > root->val){
                        if(first == NULL){
                            first = pre ;
                        }
                        second = root ;

                    }
                    pre =root ;
                    root = root->right ;
                    
                }
            }
        }
    }
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL ;
        TreeNode* first =NULL ;
        TreeNode* second= NULL ;

        bst(root, pre , first , second);
        swap(first->val , second->val);
    }
};