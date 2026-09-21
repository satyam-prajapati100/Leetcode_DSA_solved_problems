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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()){
            return NULL ;
        }

        map<int , int> Hm ;

        for(int i=0 ; i<inorder.size() ; i++){
            Hm[inorder[i]]=i;
        }


        return buildTreePostIn(inorder , 0 , inorder.size()-1 , postorder , 0 , postorder.size()-1 , Hm);
    }

    TreeNode* buildTreePostIn(vector<int>&inorder , int instart , int inend , vector<int>&postorder , int poststart , int postend , map<int ,int>&Hm){
         if(poststart> postend || instart>inend) return NULL ;

         TreeNode * root = new TreeNode(postorder[postend]);

         int inRoot = Hm[postorder[postend]];
         int numLeft = inRoot - instart ;

         root->left = buildTreePostIn(inorder, instart, inRoot-1 , postorder , poststart ,poststart + numLeft-1 , Hm);

         root->right = buildTreePostIn(inorder, inRoot+1 , inend , postorder  , poststart+numLeft , postend-1 , Hm);

         return root; 
    }


};