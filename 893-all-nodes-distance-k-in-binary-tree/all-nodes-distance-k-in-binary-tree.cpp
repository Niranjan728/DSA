/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* root,map<TreeNode*,TreeNode*> &mp){
    if(root==NULL) return;
    if(root->left){
        mp[root->left]=root;
        helper(root->left,mp);
    }
    if(root->right){
        mp[root->right]=root;
        helper(root->right,mp);
    }
}





class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> mp;
        vector<int> ans;

        helper(root,mp);
      
        queue<TreeNode*> q;
        q.push(target);
        int cnt=0;unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        while(!q.empty()){
            if(cnt==k) break;
            cnt++;
            
            int size=q.size();
            {
                for(int i=0;i<size;i++){
                    TreeNode* node=q.front();
                    q.pop();
                    if(node->left && !visited[node->left]) {q.push(node->left);visited[node->left]=true;}
                    if(node->right && !visited[node->right]){
                        q.push(node->right);
                        visited[node->right]=true;
                    }
                    if(mp.find(node)!=mp.end() && !visited[mp[node]]){
                        visited[mp[node]]=true;
                        q.push(mp[node]);

                    }
                }

            }

        }
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);

        }
 return ans;   }
};