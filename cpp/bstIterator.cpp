// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/

#include <cassert>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    explicit BSTIterator(TreeNode* root) : node_stack{root} {
        goLeftmost();
    }

    int next() {
        TreeNode *current = node_stack.back();
        node_stack.pop_back();

        if (current->right) {
            node_stack.push_back(current->right);
            goLeftmost();
        }

        return current->val;
    }

    bool hasNext() {
        return !node_stack.empty();
    }

private:
    void goLeftmost() {
        while (node_stack.back()->left) {
            node_stack.push_back(node_stack.back()->left);
        }
    }

    std::vector<TreeNode*> node_stack;
};

int main()
{
    TreeNode left(3);
    TreeNode right_left(9);
    TreeNode right_right(20);
    TreeNode right(15, &right_left, &right_right);
    TreeNode root(7, &left, &right);

    BSTIterator bSTIterator(&root);
    assert(bSTIterator.next() == 3);
    assert(bSTIterator.next() == 7);
    assert(bSTIterator.hasNext() == true);
    assert(bSTIterator.next() == 9);
    assert(bSTIterator.hasNext() == true);
    assert(bSTIterator.next() == 15);
    assert(bSTIterator.hasNext() == true);
    assert(bSTIterator.next() == 20);
    assert(bSTIterator.hasNext() == false);

    return 0;
}