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
    vector<int> topView(Node *root) {
        queue<pair<Node*, int>> q;
        q.push({root,0});
        map<int, int>mp;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto pair= q.front();
                q.pop();
                Node* curr=pair.first;
                int code= pair.second;
                mp.insert({code,curr->data});
                if(curr->left!=nullptr) q.push({curr->left,code-1});
                if(curr->right) q.push({curr->right, code+1});
            }
        }
        vector<int>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};