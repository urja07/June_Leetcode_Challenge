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
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res=0;
        calc(root,0,res);
        return res;
    }
    void calc(TreeNode* root, int val, int &res)
    {
        int p = val*10+root->val;
        
        if(!root->left && !root->right){
            res+=p;
            return ;
        }
        if(root->left)
            calc(root->left,p,res);
        if(root->right)
            calc(root->right,p,res);
    }
};
