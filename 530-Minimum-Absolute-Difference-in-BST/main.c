#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define min(a, b) (a >= b ? b : a)

int getMinDiffPrefix(struct TreeNode *root, int *prefix) {
    if (root == NULL) {
        return INT_MAX;
    }

    int leftMin = getMinDiffPrefix(root->left, prefix);

    int currentMin = INT_MAX;
    if (*prefix >= 0) {
        currentMin = abs(*prefix - root->val);
    }
    *prefix = root->val;

    int rightMin = getMinDiffPrefix(root->right, prefix);

    return min(min(leftMin, rightMin), currentMin);
}

int getMinimumDifference(struct TreeNode *root){
    int prefix = INT_MIN;
    return getMinDiffPrefix(root, &prefix);
}

int main() {
    return 0;
}
