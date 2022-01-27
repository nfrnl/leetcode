// 1305. All Elements in Two Binary Search Trees
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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

class InOrderIterator {
public:
    InOrderIterator(TreeNode* root) : current_(root) {
        if (!current_) {
            return;
        }
        while (current_->left) {
            stack_.push_back(current_);
            current_ = current_->left;
        }
    }

    void next() {
        if (current_->right) {
            current_ = current_->right;
            while (current_->left) {
                stack_.push_back(current_);
                current_ = current_->left;
            }
        }
        else if (stack_.empty()) {
            current_ = nullptr;
            return;
        }
        else {
            current_ = stack_.back();
            stack_.pop_back();
        }
    }

    int operator*() {
        return current_->val;
    }

    operator bool() {
        return current_ != nullptr;
    }
private:
    TreeNode* current_;
    std::vector<TreeNode*> stack_;
};

std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    InOrderIterator iter1{ root1 }, iter2{ root2 };
    std::vector<int> elements;
    while (iter1 || iter2) {
        if (!iter1) {
            elements.push_back(*iter2);
            iter2.next();
        }
        else if (!iter2) {
            elements.push_back(*iter1);
            iter1.next();
        }
        else {
            const int val1 = *iter1;
            const int val2 = *iter2;
            if (val1 <= val2) {
                elements.push_back(val1);
                iter1.next();
            }
            else {
                elements.push_back(val2);
                iter2.next();
            }
        }
    }
    return elements;
}

int main()
{
    {
        TreeNode first_lt{ 1 };
        TreeNode first_rt{ 4 };
        TreeNode first_root{ 2, &first_lt, &first_rt };

        TreeNode second_lt{ 0 };
        TreeNode second_rt{ 3 };
        TreeNode second_root{ 1, &second_lt, &second_rt };

        std::vector<int> expected{ 0, 1, 1, 2, 3, 4 };

        assert(getAllElements(&first_root, &second_root) == expected);
    }

    {
        TreeNode first_rt{ 8 };
        TreeNode first_root{ 1, nullptr, &first_rt };

        TreeNode second_lt{ 1 };
        TreeNode second_root{ 8, &second_lt, nullptr };

        std::vector<int> expected{ 1, 1, 8, 8 };

        assert(getAllElements(&first_root, &second_root) == expected);
    }

    return 0;
}
