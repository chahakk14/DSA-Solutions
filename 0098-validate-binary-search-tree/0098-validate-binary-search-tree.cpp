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
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == NULL) return;
        inorder(node->left, result);      
        result.push_back(node->val);      
        inorder(node->right, result);     
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        inorder(root, result);
        return result;
    }
    bool isSorted(const vector<int>& v) {
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] <= v[i - 1])
            return false;
    }
    return true;
}
public:
    bool isValidBST(TreeNode* root) {
        vector<int> input= inorderTraversal(root);
        if(isSorted(input)==true) return true;
        else return false;
    }
};