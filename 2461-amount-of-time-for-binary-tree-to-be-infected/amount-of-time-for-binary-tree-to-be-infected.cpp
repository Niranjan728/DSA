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
TreeNode* helper(TreeNode* root,int k){
    if(root==NULL) return NULL;
    TreeNode* left=helper(root->left,k);
    TreeNode* right=helper(root->right,k);
    if(left) return left;
    if(right) return right;
    if(root->val==k) return root;
return NULL;
}
void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
if(root->left) {mp[root->left]=root;parent(root->left,mp);}
if(root->right) {mp[root->right]=root;parent(root->right,mp);}

}



class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        int time=0;
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_map<TreeNode*,bool> visited;
        if(root==NULL) return 0;
        parent(root,mp);
        TreeNode* target=helper(root,start);
        if(target==NULL) return 0;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]) {q.push(node->left);visited[node->left]=true;}
                if(node->right && !visited[node->right]){q.push(node->right);visited[node->right]=true;
                }
                if(mp.find(node)!=mp.end() && !visited[mp[node]]){
                    q.push(mp[node]);
                    visited[mp[node]]=true;
                }
            }
            
        }
    


        
   return --time; }
};