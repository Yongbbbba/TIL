# leetcode 543 Diameter Of BInary Tree

- 특정  노드의 위치에서 좌측 자식의 깊이와 우측 자식의 깊이의 합을 구하면 diameter가 나오는 것까지는 생각을 해냈는데,  이를 재귀적으로 구현해내지 못했다.. 마지막 return 부분을 생각해내기가 어려웠다. 재귀적으로 생각해야하는데 그게 참 어려운 것 같다.



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
    int postOrder(TreeNode* node)
    {
        int leftDepth = 0, rightDepth = 0;
        
        if (node->left)
            leftDepth = postOrder(node->left);
        if (node->right)
            rightDepth = postOrder(node->right);
        int cntDepth = leftDepth + rightDepth;
        result = max(result, cntDepth);
        
        return max(leftDepth, rightDepth) + 1;  // 현재 노드가 가지는 최대 깊이
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root->left == nullptr &&  root->right == nullptr) return 0;
       postOrder(root);
        return result;
    }
    
    int result = 0;
};
```







