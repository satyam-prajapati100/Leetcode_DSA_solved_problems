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

    int find(TreeNode * root , int &dia){
         if(!root){
            return 0;
        }

    

        int L = find(root->left ,dia);
        int R =find(root->right ,dia);
        dia= max(dia ,L+R);

        return 1+max(L ,R);
    }

       
    
    int diameterOfBinaryTree(TreeNode* root) {
      int dia = 0 ;

      find(root, dia);

      return dia ;

    }
};