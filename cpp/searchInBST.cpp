// 700. Search in a Binary Search Tree
// https://leetcode.com/problems/search-in-a-binary-search-tree/

#include <cassert>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        auto current = root;
        while (current) {
            if (current->val == val) {
                return current;
            } else if (current->val > val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return current;
    }
};

int main()
{
    {
        TreeNode left_left{1};
        TreeNode left_right{3};
        TreeNode left{2, &left_left, &left_right};
        TreeNode right{7};
        TreeNode root{4, &left, &right};

        auto result1 = Solution().searchBST(&root, 2);
        assert(result1 == &left);

        auto result2 = Solution().searchBST(&root, 5);
        assert(result2 == nullptr);
    }

    return 0;
}