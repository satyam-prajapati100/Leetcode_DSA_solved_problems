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

    void levelorder(TreeNode* root , vector<vector<int>> &ans , vector<int> &temp){
        if(!root){
            return ;
        }

        queue<TreeNode*>q;
        q.push(root);

        TreeNode* curent ;

        while(!q.empty()){
            int size= q.size();
            temp.clear();
            for(int i=0 ;i<size ;i++){
                curent = q.front();
                q.pop();
                temp.push_back(curent->val);
    
                if(curent->left){
                    q.push(curent->left);
                }
                if(curent->right){
                    q.push(curent->right);
                }
            }
            ans.push_back(temp);

        }
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int> temp;

        levelorder(root, ans , temp);
        return ans ;

    }
};