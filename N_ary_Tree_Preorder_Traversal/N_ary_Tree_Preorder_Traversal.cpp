class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* cur = stk.top();
            stk.pop();
            result.push_back(cur -> val);
            for (int i = cur -> children.size() - 1; i >= 0; i--) {
                if (cur -> children[i] != nullptr) {
                    stk.push(cur -> children[i]);
                }
            }
        }
        return result;
    }
};

/* recursive
class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(root==nullptr)
            return res;
        res.push_back(root->val);
        for(Node* child:root->children)
            preorder(child);
        return res;
    }
};
*/