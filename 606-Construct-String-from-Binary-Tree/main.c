#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void treeNode2Str(struct TreeNode *t, char *result, int *index, const int max_index) {
    if (!t || *index >= max_index) {
        return;
    }

    sprintf(result + *index, "%d", t->val);
    while(result[++ (*index)]) {
    }

    if (!t->left && !t->right) {
        return;
    }

    result[(*index) ++] = '(';
    treeNode2Str(t->left, result, index, max_index);
    result[(*index) ++] = ')';

    if (t->right) {
        result[(*index) ++] = '(';
        treeNode2Str(t->right, result, index, max_index);
        result[(*index) ++] = ')';
    }
}

char *tree2str(struct TreeNode *t) {
    if (!t) {
        return NULL;
    }

    const int max_index = 2000;
    char *result = (char *)malloc(sizeof(char) * max_index);
    memset(result, 0 , sizeof(char) * max_index);
    int index = 0;
    treeNode2Str(t, result, &index, max_index);

    return result;
}

typedef struct TreeNode TreeNode_t;

int main() {
    TreeNode_t *root = (TreeNode_t*)malloc(sizeof(TreeNode_t));
    root->left = (TreeNode_t*)malloc(sizeof(TreeNode_t));
    root->right = (TreeNode_t*)malloc(sizeof(TreeNode_t));
    root->left->left = (TreeNode_t*)malloc(sizeof(TreeNode_t));

    root->val = 1;

    root->left->val = 2;
    root->left->right = NULL;

    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    root->left->left->val = 4;
    root->left->left->left = NULL;
    root->left->left->right = NULL;

    tree2str(root);

    return 0;
}
