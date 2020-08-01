#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define max(a, b) (a >= b ? a : b)
int g_result;

int diameterOfBinaryTreeRecursive(struct TreeNode *root) {
    if (!root) {
        return 0;
    }

    int left_result = diameterOfBinaryTreeRecursive(root->left);
    int right_result = diameterOfBinaryTreeRecursive(root->right);

    if (left_result + right_result > g_result) {
        g_result = left_result + right_result;
    }
    return max(left_result + 1, right_result + 1);
}

int diameterOfBinaryTree(struct TreeNode *root){
    g_result = 0;
    diameterOfBinaryTreeRecursive(root);
    return g_result;
}

int main() {
    return 0;
}
