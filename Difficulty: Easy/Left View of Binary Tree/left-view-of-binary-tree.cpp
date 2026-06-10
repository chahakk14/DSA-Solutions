/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        if(root==NULL) return {};
        queue<Node*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            if (i == 0) ans.push_back(curr->data);
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }
    return ans;
        
    }
};