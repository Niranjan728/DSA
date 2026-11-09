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
    int countNodes(TreeNode* root) {
        int left=0;
        TreeNode* temp=root;
        while(temp){
            temp=temp->left;
            left++;

        }
        int right=0;
        temp=root;
        while(temp){
            temp=temp->right;
            right++;

        }
        if(left==right){
            return (1<<left)-1;
        }
        else {
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};