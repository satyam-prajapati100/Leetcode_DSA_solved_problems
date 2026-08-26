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

    void zigzagOrder(TreeNode* root , vector<int> &curent , vector<vector<int>> &ans){
        if(!root){
            return ; 
        }

        stack<TreeNode *> s1 , s2 ; 
        s1.push(root);

        while(!s1.empty() || !s2.empty()){
            curent.clear();
            if(!s1.empty()){
                while(!s1.empty()){
                    TreeNode * temp = s1.top();
                    s1.pop();

                    curent.push_back(temp->val);

                    if(temp->left){
                        s2.push(temp->left);
                    }

                    if(temp->right){
                        s2.push(temp->right);
                    }
                }
            }
            else{
                while(!s2.empty()){
                    TreeNode* temp = s2.top();
                    s2.pop();

                    curent.push_back(temp->val);
                    if(temp->right){
                        s1.push(temp->right);
                    }

                    if(temp->left){
                        s1.push(temp->left);
                    }
                }
            }

            ans.push_back(curent);
        }

    
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> curent ;
        vector<vector<int>> ans ; 
 
        zigzagOrder(root , curent , ans);

        return ans ; 

    }
};