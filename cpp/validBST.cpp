// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

#include <cassert>
#include <optional>
#include <vector>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode* root) {
    if (!root) {
        return true;
    }

    std::vector<TreeNode*> stack;
    TreeNode* node = root;
    std::optional<int> prev_value;

    while (!stack.empty() || node) {
        if (node) {
            stack.push_back(node);
            node = node->left;
        }
        else {
            node = stack.back();
            stack.pop_back();

            if (prev_value && *prev_value >= node->val) {
                return false;
            }
            prev_value = node->val;

            node = node->right;
        }
    }

    return true;
}

int main() {
    {
        TreeNode left{ 1 };
        TreeNode right{ 3 };
        TreeNode root{ 2, &left, &right };

        assert(isValidBST(&root));
    }
    {
        TreeNode rt_lt{ 3 };
        TreeNode rt_rt{ 6 };
        TreeNode rt{ 4, &rt_lt, &rt_rt };
        TreeNode lt{ 1 };
        TreeNode root{ 5, &lt, &rt };

        assert(!isValidBST(&root));
    }

    return 0;
}
