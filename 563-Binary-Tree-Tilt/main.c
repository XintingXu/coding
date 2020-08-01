#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int result = 0;

int findTiltRecursive(struct TreeNode *root) {
    if (!root) {
        return 0;
    }

    int left_sum = findTiltRecursive(root->left);
    int right_sum = findTiltRecursive(root->right);

    result += abs(left_sum - right_sum);

    return left_sum + right_sum + root->val;
}

int findTilt(struct TreeNode *root){
    if (!root) {
        return 0;
    }

    result = 0;
    findTiltRecursive(root);

    return result;
}

int main() {
    return 0;
}
