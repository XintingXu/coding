#include <stdio.h>

#define bool short
#define true 1
#define false 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *s, struct TreeNode *t) {
    if ((!s && t) || (s && !t)) {
        return false;
    }

    if (!s && !t) {
        return true;
    }

    return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(struct TreeNode *s, struct TreeNode *t) {
    if (isSameTree(s, t)) {
        return true;
    }

    if (!s && t) {
        return false;
    }

    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main() {
    return 0;
}
