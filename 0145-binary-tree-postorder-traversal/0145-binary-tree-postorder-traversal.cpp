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

    void postorder(TreeNode * root , vector<int> &ans){
        if(!root){
            return;
        }

        stack<TreeNode* > str1 , str2 ;

        str1.push(root);

        while(!str1.empty()){
            root= str1.top();
            str1.pop();

            if(root->left){
                postorder(root->left , ans);
            }

            if(root->right){
                postorder(root->right , ans);

            }

            str2.push(root);
        }

        while(!str2.empty()){
            ans.push_back(str2.top()->val);
            str2.pop();
        }

    
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans ;

        postorder(root ,ans );

        return ans ;
    }
};