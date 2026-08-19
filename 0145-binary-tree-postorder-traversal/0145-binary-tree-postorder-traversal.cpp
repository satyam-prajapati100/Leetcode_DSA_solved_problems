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
    void postOrder_iterative(TreeNode * root , vector<int> &ans){
        if(!root){
            return ;
        }

        stack<TreeNode *>st;
        st.push(root);

        while(!st.empty()){
            root= st.top();
            st.pop();

            ans.push_back(root->val);

            if(root->right){
                postOrder_iterative(root->right ,ans);

            }

            if(root->left){
                postOrder_iterative(root->left , ans);
            }


        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans ;

        postOrder_iterative(root , ans);

        reverse(ans.begin(), ans.end());
        return ans ;
    }
};