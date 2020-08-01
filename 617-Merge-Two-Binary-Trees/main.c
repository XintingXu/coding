#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(!t1 && !t2) {
        return NULL;
    }

    struct TreeNode *result = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    result->val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);

    result->left = mergeTrees((t1 ? t1->left : NULL), (t2 ? t2->left : NULL));
    result->right = mergeTrees((t1 ? t1->right : NULL), (t2 ? t2->right : NULL));

    return result;
}

int main() {
    return 0;
}
