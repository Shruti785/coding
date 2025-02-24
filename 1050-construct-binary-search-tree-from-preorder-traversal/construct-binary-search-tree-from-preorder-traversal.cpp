class Solution {
private:
    // Function to recursively build BST from preorder
    TreeNode* solve(vector<int>& pre, int min, int max, int& i)
    {
        // Base case: If index goes out of range
        if(i >= pre.size()) return NULL;

        // If the current value is out of the allowed range
        if(pre[i] < min || pre[i] > max) return NULL;

        // Create the current node
        TreeNode* root = new TreeNode(pre[i++]);

        // Construct the left subtree (values must be < root->val)
        root->left = solve(pre, min, root->val, i);

        // Construct the right subtree (values must be > root->val)
        root->right = solve(pre, root->val, max, i);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;  // Track position in preorder array
        return solve(preorder, INT_MIN, INT_MAX, i);
    }
};
