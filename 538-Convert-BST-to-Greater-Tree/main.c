#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void convertBSTNode(struct TreeNode *root, int *prefixSum) {
    if (root == NULL) {
        return;
    }

    convertBSTNode(root->right, prefixSum);

    *prefixSum += root->val;
    root->val = *prefixSum;

    convertBSTNode(root->left, prefixSum);
}

struct TreeNode* convertBST(struct TreeNode *root) {
    int prefixSum = 0;
    convertBSTNode(root, &prefixSum);
    return root;
}

int main() {
    return 0;
}
