# leetcode 112 Path Sum

dfs를 사용해서 탐색

```c++
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
    void dfs(TreeNode* node, int targetSum, int cntSum)
    {
        
        // 자식이 없다면 leaf node 
        if (node->left == nullptr && node->right == nullptr)
        {
            if (targetSum == cntSum)
            {
                result = true;
            }
            return;
        }
        
        if (result ==true) return;
        
        if (node->left)
        {
            dfs(node->left, targetSum, cntSum+node->left->val);
        }
        if (node->right)
        {
            dfs(node->right, targetSum, cntSum+node->right->val);
        }
        
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        dfs(root, targetSum, root->val);
        
        return result;
    }
    
    bool result = false;
};
```

