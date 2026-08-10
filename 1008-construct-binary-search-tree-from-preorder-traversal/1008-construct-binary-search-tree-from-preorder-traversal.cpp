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

    TreeNode* helper(vector <int> preOrder, int &i , int bound){
        if( i>= preOrder.size() || preOrder[i] >= bound) return NULL ;

        TreeNode* root = new TreeNode(preOrder[i]) ;
        i++ ;

        root->left = helper(preOrder,i,root->val) ;

        root->right = helper(preOrder,i,bound) ;

        return root ;
    }

    TreeNode* bstFromPreorder(vector<int>& preOrder) {
        int i = 0 ;
        int bound = INT32_MAX ;
        return helper(preOrder,i,bound) ;
    }
};